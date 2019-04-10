#include <iostream>
using namespace std;

int bracket(const char str[],int s_size){
    int i,j,k,l;
    int **dp=new int*[s_size+1];
    for(i=0;i<s_size+1;i++)
        dp[i]=new int[s_size+1];

    for(i=1;i<=s_size;i++)
        dp[i][i-1]=0,dp[i][i]=1;
    for(i=1;i<=s_size-1;i++)
        for(j=1;j<=s_size-i;j++){
            k=i+j;
            dp[j][k]=0x7fffffff;
            if((str[j]=='('&&str[k]==')')||(str[j]=='['&&str[k]==']'))
                dp[j][k]=min(dp[j][k],dp[j+1][k-1]);
            if(str[j]=='('||str[j]=='[')
                dp[j][k]=min(dp[j][k],dp[j+1][k]+1);
            if(str[k]==')'||str[k]==']')
                dp[j][k]=min(dp[j][k],dp[j][k-1]+1);
            for(l=j;l<=k-1;l++)
                dp[j][k]=min(dp[j][k],dp[j][l]+dp[l+1][k]);
        }
    return dp[1][s_size];
}

int main(){
    int s_size;
    cin>>s_size;
    int i;
    char str[s_size];
    for(i=0;i<s_size;i++)
        cin>>str[i];
    cout<<bracket(str,s_size);

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
 */
