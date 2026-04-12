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

ll h,w;
matrix a;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>h>>w;
	vector<string> vs;
	vs.resize(h);
	rep(i,h){
		cin>>vs[i];
	}
	Vi tmp;
	string ts;
	rep(i,w){
		ts.pb('.');
	}
	rep(i,h){
		if(vs[i]==ts){
			tmp.pb(i);
		}
	}
	reverse(all(tmp));
	rep(i,tmp.size()){
		vs.erase(vs.begin()+tmp[i]);
	}
	vector<string> vs2(w,string(vs.size(),' '));
	rep(i,vs.size()){
		rep(j,w){
			vs2[j][i]=vs[i][j];
		}
	}
	tmp.clear();
	ts.clear();
	rep(i,vs.size()){
		ts.pb('.');
	}
	rep(i,vs2.size()){
		if(vs2[i]==ts){
			tmp.pb(i);
		}
	}
	reverse(all(tmp));
	rep(i,tmp.size()){
		vs2.erase(vs2.begin()+tmp[i]);
	}
	vector<string> as(vs2[0].size(),string(vs2.size(),' '));
	rep(i,vs2.size()){
		rep(j,vs2[0].size()){
			as[j][i] = vs2[i][j];
		}
	}
	rep(i,as.size()){
		print(as[i]);
	}
	return 0;
}