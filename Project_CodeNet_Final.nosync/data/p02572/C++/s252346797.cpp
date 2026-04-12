#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define up_b upper_bound
#define low_b lower_bound
#define nl '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const int N=2e5+11;
const int M=1e5+1;
const int inf=2e9+1;
const ld EPS=1e-6;
const ll INF=1e18;
const ll mod=/*998244353*/1e9+7;
const int dx[8]={0,0,-1,1,-1,1,1,-1};
const int dy[8]={-1,1,0,0,1,-1,1,-1};

ll a[N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int n;
  cin>>n;
  ll sum=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum+=a[i];
    sum%=mod;
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    sum=(sum-a[i]+mod)%mod;
    ll res=(sum*a[i])%mod;
    ans=(ans+res)%mod;
  }
  cout<<ans;
}
