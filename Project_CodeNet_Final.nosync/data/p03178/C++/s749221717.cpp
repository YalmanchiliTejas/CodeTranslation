#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
typedef pair<ll,pii> ipii;
#define MOD 1000000007
#define mod(a) ((a)%MOD)
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<"\n"
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<"\n"
#define INF (1LL<<60)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()
#define endl '\n'
ll gcd(ll a,ll b){if(a==0) return b; return gcd(b%a,a);}
ll powm(ll base,ll exp,ll mod=MOD) {base%=mod;ll ans=1;while(exp){if(exp&1LL) ans=(ans*base)%mod;exp>>=1LL,base=(base*base)%mod;}return ans;}
 

ll dp[10004][101];
int main(){
      sync;
      string k;
      ll d;
      cin>>k>>d;
   
      dp[0][0]=1;
      for(int i=1;i<=k.size();i++){
          for(int j=0;j<d;j++){
              for(int x=0;x<=9;x++)
                   dp[i][j]=mod(dp[i][j]+dp[i-1][(10*d+j-x)%d]);
          }
      }

        ll ans=0;
        ll res=0;
        for(int i=0;i<k.size();i++){
             for(int j=0;j<k[i]-'0';j++){
                    ans = mod(ans+dp[k.size()-1-i][(2*d-res-j)%d]);                 
             }
                 res = (2*d+res+k[i]-'0')%d;
        }

               ans=mod(MOD+ans-1+(res%d==0));
               cout<<ans<<endl;
}