#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> s(N);
    REP(i, N) cin >> s[i];

    ll res = 0;
    REP(C, N+1){
    	ll k = 0;
    	ll tmp = 0;
    	set<ll> st;
    	while(1){
    		ll A = N-1-k*C;
    		ll B = A-C;
    		if(A<0||B<0) break;
    		if(k*C>N-1) break;
    		if(st.find(A) != st.end()) break;
    		st.insert(A);
    		tmp += s[A];
    		if(st.find(k*C) != st.end()) break;
    		st.insert(k*C);
    		tmp += s[k*C];
    		res = max(res, tmp);
    		k++;
    	}
    }
    cout << res << endl;
    return 0;
}