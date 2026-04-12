#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
//const ull mod = 1e9 + 7;
const ll mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

// conversion number to bit
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
    bit += char('0'+(num>>i & 1));
  }
  return bit;
}

ll G[10][10] = {};
ll N, M;

int solve(vector<ll> &perm){
	if(perm[0] != 0) return 0;
	bool ok = true;
	REP(i, N-1){
		if(G[perm[i]][perm[i+1]]!=1) ok = false;
	}
	return (ok ? 1 : 0);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    REP(i, M){
	    ll a, b;
	    cin >> a >> b;
	    a--, b--;
	    G[a][b] = 1;
	    G[b][a] = 1;
	}

    vector<ll> perm(N);
    REP(i, N) perm[i] = i;
	bool flag = true;
	ll res = 0;
	while(flag){
		//vprint(perm2);
		res += solve(perm);
		flag = next_permutation(perm.begin(), perm.end());
	}
	cout << res << endl;
    return 0;
}