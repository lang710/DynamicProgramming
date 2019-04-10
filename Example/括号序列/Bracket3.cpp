#include <iostream>
using namespace std;

int bracket(char str[],int s_size){
    int **dp=new int*[s_size];
    int i,j,k;
    for(i=0;i<s_size;i++)
        dp[i]=new int[s_size];
    
    /*
    dp[i][j]表示从str中第i到第j之间为满足规则需要填充的字符个数
    dp[0][s_size-1]表示整个str为满足规则需要填充的字符个数
    dp状态转移方程：
    dp[i][j]=0,i>j
    dp[i][j]=1,i=j
    dp[i][j]=min(...)
    */
    for(i=0;i<s_size;i++)
        for(j=0;j<s_size;j++)
            if (i > j)
                dp[i][j]=0;
            else if(i==j)
                dp[i][j]=1;
            else
                dp[i][j]=0x7fff;      //注意此处不能设置为0x7fffffff,因为0x7fffffff+1之后等于-1，除非设置为unsigned int类型

    for(i=s_size-2;i>=0;i--)
        for(j=i+1;j<s_size;j++) {
            if ((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']'))
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            if(str[i]=='('||str[i]=='[')
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
            if(str[j]==')'||str[j]==']')
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            for(k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    return dp[0][s_size-1];
}

int main(){
    int s_size;
    cin>>s_size;
    int i;
    char str[s_size];
    for(i=0;i<s_size;i++)
        cin>>str[i];
    cout<<bracket2(str,s_size);

    return 0;
}

/*
 *
 *
算法时间复杂度为O^3：

input:
4
([()
output:
2

input:
2
)(
output:
2

input:
18
(][[[[()[[][((([)(
output:
12
 *
 */
