#include <iostream>
using namespace std;

int bracket(char str[],int i,int j){
    if(i>j)
        return 0;
    else if(i==j)
        return 1;
    else{
        int answer=0x7fffffff;
        if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
            answer=min(answer,bracket(str,i+1,j-1));
        if(str[i]=='('||str[i]=='[')
            answer=min(answer,bracket(str,i+1,j)+1);
        if(str[j]==')'||str[j]==']')
            answer=min(answer,bracket(str,i,j-1)+1);
        for(int k=i;k<j;k++)
            answer=min(answer,bracket(str,i,k)+bracket(str,k+1,j));
        return answer;
    }
}

int main(){
    int s_size;
    cin>>s_size;
    char str[s_size];
    int i;
    for(i=0;i<s_size;i++)
        cin>>str[i];
    
    cout<<bracket(str,0,s_size-1);
    return 0;
}

/*
算法评估：
时间复杂度：指数级

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
 *
 */
  
