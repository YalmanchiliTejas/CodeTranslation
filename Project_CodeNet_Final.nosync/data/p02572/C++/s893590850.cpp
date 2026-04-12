#include<bits/stdc++.h>
using namespace std;


long long ara[2000009];
int main()
{
  ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
 // freopen("in.txt","r",stdin);
long long i,j,n,sum=0;
long long M=1000000007;

scanf("%lld",&n);

for(i=1;i<=n;i++)
{
scanf("%lld",&ara[i]);
sum+=ara[i];
sum%=M;
}
long long total=0;
for(i=1;i<n;i++)
{
 sum-=ara[i];
 if(sum<0) sum+=M;
 total+=(sum*(ara[i]%M))%M;
}
total=(total%M);

printf("%lld\n",total);

  return 0;
}
