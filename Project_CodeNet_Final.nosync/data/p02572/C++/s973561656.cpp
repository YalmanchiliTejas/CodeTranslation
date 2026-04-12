#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define dloop(i,a,b) for(ll i=a;i>=b;--i)
#define all(a) a.begin(),a.end()
#define lar 1000000007
#define pq priority_queue
#define pll pair<ll,ll>
#define ss second
#define ff first
#define pb push_back
#define ppb pop_back
#define umap unordered_map
#define ub upper_bound
#define lb lower_bound
#define br "\n"
#define sp " "
const int N=1e5;

void solve(){
	ll n;
  cin>>n;
  ll a[n];
  loop(i,0,n) cin>>a[i];
  ll pre[n];
  pre[0] = a[0];
  ll ans=0;
  loop(i,1,n)
    pre[i] = (pre[i-1]+a[i])%lar;
  loop(i,1,n)
  {
    ans = (ans+(pre[i-1]*a[i])%lar)%lar;
  }
  cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
