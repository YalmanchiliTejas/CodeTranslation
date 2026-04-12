#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define INF (int)1e9+4
#define INFL (ll)1e18+4
#define md (int)1e9+7
#define mx 10000000  //use fixed<<setprecion
#define mk make_pair
#define pi pair<int,int>
#define ss second
#define ff first
#define pb emplace_back
#define onell(x) __builtin_popcountll(x)
#define one(x) __builtin_popcount(x)
#define maxi(a) *max_element(a.begin(),a.end());
#define mini(a) *min_element(a.begin(),a.end());
#define all(s) s.begin(),s.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(x, a) for (auto& x: a)
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sz(x) ((long long)x.size())
#define mez(s) memset(s,0,sizeof s)
#define mex(s) memset(s,-1,sizeof s)
#define metr(s) memset(s,true, sizeof s)
typedef vector<int> vi;
typedef vector<ll>vl;
typedef map<int,int> mp;
typedef queue<int> que;
typedef vector<pi> vp;
const int mod=1e9+7;
void solve(){
ll n=0,x=0,y=0,z=0,m=0,k=0;ll ans=0;
cin>>n;
vl a(n);rep(i,0,n)cin>>a[i];
reverse(all(a));
vl pre(n-1);pre[0]=a[0];
rep(i,1,n-1){
	pre[i]=pre[i-1]+a[i];
}
reverse(all(pre));
pre.pb(0);
reverse(all(a));
rep(i,0,n){
//	cout<<pre[i]<<" "<<a[i]<<"\n";
	ans=ans+((pre[i]%mod)*a[i])%mod;
	ans%=mod;
}
cout<<ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
