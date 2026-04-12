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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll res = 0;
    ll m = (N-2)/2;
    if(N%2==0){
    	REP(i, m) res += -2 * A[i];
    	REP(i, m) res += 2 * A[N-1-i];
    	res -= A[m];
    	res += A[m+1];
    }else{
    	ll cand1 = 0;
    	REP(i, m+1) cand1 += -2*A[i];
    	REP(i, m) cand1 += 2*A[N-1-i];
    	cand1 += A[m+1];
    	cand1 += A[m+2];

    	ll cand2 = 0;
    	REP(i, m) cand2 += -2*A[i];
    	REP(i, m+1) cand2 += 2*A[N-1-i];
    	cand2 -= A[m];
    	cand2 -= A[m+1];

    	res = max(cand1, cand2);
    }
    cout << res << endl;
    return 0;
}