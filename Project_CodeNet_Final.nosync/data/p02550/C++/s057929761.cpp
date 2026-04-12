#include <bits/stdc++.h>

#define f(i,a,b) for( ll  i = a; i < (ll) b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter   ios::sync_with_stdio(false);cin.tie(0)

// policy-based



using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 2e6+1;
const ll inf = 1e9;
const ll mod = 998244353;


ll res[MAX];
ll pos[MAX];
int main(){
	fastio;
	ll n,x,m,per,ini;
	cin >> n >> x >> m;
	if(x == 0){
		cout << "0\n";
		return 0;
	}
	res[0] = x%m;
	f(i,0,MAX) pos[i] = -1;
	pos[ res[0] ] = 0;
	f(i,1,MAX){
		res[i] = (res[i-1]*res[i-1])%m;
		if(pos[ res[i]] != -1) {
			ini = pos[res[i]];
			per = i - ini ;
			break;
		}
		pos[res[i]] = i;
	}	

	ll ans = 0,sum =0;
	if(n <= ini) f(i,0,n) ans += res[i];
	else{
		f(i,0,ini) ans += res[i];
		f(i,ini,ini+per) sum += res[i];
		f(i,ini, ini +  (n-ini)%per ) ans += res[i];
		ans += sum * ( (n-ini)/per);

	}

	cout << ans - res[0] + x << endl;
	return 0;
} 