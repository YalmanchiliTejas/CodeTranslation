#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n,x;
Vi dps;
Vi dpp;

ll cals(ll n){
	if(dps[n]!=-1)return dps[n];

	if(n==0)return 1;
	else{
		return dps[n] = 3+cals(n-1)*2;
	}
}

ll calp(ll n){
	if(dpp[n]!=-1)return dpp[n];
	if(n==0)return 1;
	else{
		return dpp[n] = 1+calp(n-1)*2;
	}
}


ll calc(ll x,ll lv){
	if(x==0)return 0;
	if(x==cals(lv))return calp(lv);
	x-=1;
	if(x<=cals(lv-1)){
		return calc(x,lv-1);
	}else{
		x-=cals(lv-1)+1;
		return 1 + calc(x,lv-1) + calp(lv-1);
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n>>x;
	dps.resize(n+1,-1);
	dpp.resize(n+1,-1);
	ll ans = calc(x,n);
	print(ans);
	return 0;
}