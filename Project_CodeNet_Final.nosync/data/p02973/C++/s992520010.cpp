#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
const long long MOD = 1e9+7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}
//auto f = [&](int n)->int{return n;};
//auto a = [&](auto&&b){b(b)};



signed main(){
	int N;
	cin>>N;
	vector<int>a(N);
	multiset<int>st;
	REP(i,N)cin>>a[i];
	st.insert(-a[0]);
	FOR(i,1,N){
		auto itr = st.upper_bound(-a[i]);
		if(itr != st.end())st.erase(itr);
		st.insert(-a[i]);
	}
	cout<<st.size()<<endl;
}