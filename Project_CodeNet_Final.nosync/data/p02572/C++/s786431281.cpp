# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define pr(x) prev(x.end())
# define mset multiset
# define umap unordered_map
# define gcd __gcd
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mod = 1e9+7;//998244353
const int N = 1e5+5;



void solve(){
	int n;
	cin>>n;
	int v[n];
	ll s = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        s+=v[i];
        //s%=mod;
    }   
    ll ans = 0;
    for(int i = 0; i < n; i++){
        s-=v[i];
		ans+=((s%mod)*v[i])%mod;  
    }
    ans%=mod;
    cout<<ans;
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
