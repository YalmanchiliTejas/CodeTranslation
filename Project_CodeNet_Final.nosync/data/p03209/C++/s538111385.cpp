#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

typedef pair<ll,int>pa;

ll sum[60],p[60];

ll solve(ll n,ll x)
{

      if(n==0 && x>=1) return 1;
      else if(x<=0) return 0;
      else {
         if(x<=sum[n-1]+1)   return solve(n-1,x-1);
         else if(x==sum[n-1]+1)  return p[n-1];

         else  return  p[n-1]+1+solve(n-1,x-sum[n-1]-2);
      }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    ll n,k;cin>>n>>k;

    sum[0]=1,p[0]=1;

    for(int i=1;i<=50;i++){
        sum[i]=sum[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    cout<<solve(n,k)<<endl;
     return 0;
}
