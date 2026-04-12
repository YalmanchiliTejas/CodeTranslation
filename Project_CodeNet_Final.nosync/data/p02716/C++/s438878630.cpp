#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

ll dp[201000]={};

int main(){
   int n; cin>>n;
   vector<int> a(n); rep(i,0,n)cin>>a[i];
   vector<ll> sum(n); rep(i,0,n)sum[i]=a[i]+(i?sum[i-2]:0);
   rep(i,1,n){
      if(i&1)dp[i]=max(dp[i-2]+a[i],sum[i-1]);
      else dp[i]=max(dp[i-2]+a[i],dp[i-1]);
   } printf("%lld\n",dp[n-1]);
   return 0;
}
