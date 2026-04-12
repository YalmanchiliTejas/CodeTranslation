#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define int long long int
#define pp pair<int,int>
#define endl "\n"
#define PI 3.14159265
int MAXN = 5000001;
const int mod=1000000007;
const int INF =INT_MAX;
inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int pow(int a,int n,int mod){if(n==0)return 1;int p=pow(a,n/2,mod);p=(p%mod*p%mod)%mod;if(n%2) return (p%mod*a%mod)%mod;else return p;}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      vector<int>v(n);
      for(int i=0;i<n;i++)cin>>v[i];
       vector<int>pre(n+1,0);
       pre[n-1]=v[n-1];
       for(int i=n-2;i>=0;i--)pre[i]=(pre[i+1]%mod+v[i]%mod)%mod;
       int ans=0;
       for(int i=0;i<n;i++)
       {
          ans+=(v[i]%mod*pre[i+1]%mod)%mod;
          ans%=mod;
       }
      cout<<ans<<endl;
    }
    return 0;
}
