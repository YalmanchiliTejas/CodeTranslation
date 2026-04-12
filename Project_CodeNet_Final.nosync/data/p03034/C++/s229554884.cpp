#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
const int loose = 0;
const int tight = 1;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin>>n;
	Array s(n);
	REP(i,n) cin>>s[i];

	//a,a-b,a+a-b,..,n-1
	//c=a-b -> a,c,a+c,2*c,...,n-1
	//a+k*c=n-1 -> c,2*c,...,k*c,n-1-k*c,...,n-1
	ll ans=0;
	rep(c,1,n-1){
		ll sum=0;
		if((n-1)%c == 0){
			for(ll k=1;2*k*c<n-1;k++){
				sum+=s[k*c]+s[n-1-k*c];
				chmax(ans,sum);
			}
		}else{
			for(ll k=1;c<n-1-k*c;k++){
				sum+=s[k*c]+s[n-1-k*c];
				chmax(ans,sum);
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}