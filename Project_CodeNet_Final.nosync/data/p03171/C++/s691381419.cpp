#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define fi first
#define se second
#define lz length()
#define all(x) (x).begin(),(x).end()
#define scf(x) scanf("%lld",&x)
#define rep(i,n) for(ll i=0;i<n;i++)
const int INF = (int)1e9;
const ll IINF=1LL<<62;
const int maxn=10000005;
//int divr[maxn];
/*ll modexpo(ll a,ll b)
{
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}
void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}*/
 














const int N=3005;
int n,k;
ll a[N];
vector<pi> vec[N];
int main()
{
     cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=0;i<N;i++){
          for(int j=0;j<N;j++)
          {
               vec[i].push_back(make_pair(0,0));
          }
     }
     for(int len=1;len<=n;len++)
     {
          for(int i=1;i<=n-len+1;i++)
          {
               int j=i+len-1;
               if(vec[i+1][j].second+a[i]>vec[i][j-1].second+a[j])
               {
                    vec[i][j].first=vec[i+1][j].second+a[i];
                    vec[i][j].second=vec[i+1][j].first;
               }
               else
               {
                    vec[i][j].first=vec[i][j-1].second+a[j];
                    vec[i][j].second=vec[i][j-1].first;
               }
          }
     }
     ll res=vec[1][n].first-vec[1][n].second;
     cout<<res;
     
     
     

}























 