#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    char str[200];
    int i,j,k,l,m;
    ll n;
    scanf("%s",str);
    scanf("%lld",&n);
    ll sum=0;
     m=strlen(str);
    for(int i=0;i<m;i+=2)
    {
      if(i==0)
      {
          sum=str[i]-48;
          continue;
      }
      if(str[i-1]=='*')
      {
          sum=sum*(str[i]-48);
      }
      else sum=sum+str[i]-48;
    }
    ll sum2=0;
    for(int i=0;i<m;)
    {
       // cout<<i<<endl;
        for(j=i+1;j<m;j+=2){
            if(str[j]=='*')continue;
            break;
        }
        ll mul=1;
        for(int k=i;k<j;k+=2)
        {
            mul=mul*(str[k]-48);
        }

        sum2+=mul;
       // cout<<mul<<" "<<j<<" "<<(j+1)<<endl;
        i=j+1;
    }
    if(n==sum&&sum==sum2)
    {
        printf("U\n");
    }
    else if(n!=sum&&n!=sum2)
    {
         printf("I\n");
    }
    else if(sum==n)
    {
        printf("L\n");
    }
    else printf("M\n");



}

