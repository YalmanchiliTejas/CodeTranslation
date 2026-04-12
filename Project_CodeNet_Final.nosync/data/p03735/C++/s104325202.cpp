#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1777777777;
using PIC = pair<int32, char>;

int main(void){
	int32 N;
	vector<PLL> v;
	cin >> N;
	int64 maxi = 0, mini = INF_LL;
	REP(i, N){
		int64 a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		chmax(maxi, b);
		chmin(mini, a);
		v.push_back({a, b});
	}
	sort(all(v));
	int64 mini2 = INF_LL, maxi2 = 0;
	using tup = tuple<int64, int64, int64>;
	priority_queue<tup, vector<tup>, greater<tup>> pq;
	REP(i, v.size()){
		chmax(maxi2, v[i].fs);
		chmin(mini2, v[i].sc);
		pq.push(tup(v[i].fs, i, 0));
	}
	int64 res = (maxi-mini2)*(maxi2-mini);
	maxi2 = 0;
	REP(i, v.size()) chmax(maxi2, v[i].fs);
	chmin(res, (maxi-mini)*(maxi2-get<0>(pq.top())));
	while(get<2>(pq.top()) == 0){
		int64 val, in, id;
		tie(val, in, id) = pq.top(); pq.pop();
		chmax(maxi2, v[in].sc);
		pq.push(tup(v[in].sc, in, 1));
		chmin(res, (maxi-mini)*(maxi2-get<0>(pq.top())));
	}
	cout << res << endl;
}