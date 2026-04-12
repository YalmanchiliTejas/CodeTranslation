#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;			
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> 	pii;
typedef vector<bool> vb;
#define endl '\n'
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007
#define F first
#define S second
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define in insert
#define mp make_pair
#ifdef LOCAL
	#include "../../trace.h"
#else
    #define trace(args...)
#endif

ll div_floor(const ll &a,const ll &b) { return a / b - (((a ^ b) < 0) and a % b);}
ll div_ceil(const ll &a,const ll &b) { return a / b + (((a ^ b) >= 0) and a % b);}

void solve(){
	int X; cin>>X;
	if(X>=30) cout<<"Yes"; else cout<<"No";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifdef LOCAL
		freopen(".inp.txt", "r", stdin);
    	freopen(".out.txt", "w", stdout);
    	freopen(".err.txt", "w", stderr);
	#endif
	int t=1;
	// cin>>t;
	while(t--)
		solve();
}