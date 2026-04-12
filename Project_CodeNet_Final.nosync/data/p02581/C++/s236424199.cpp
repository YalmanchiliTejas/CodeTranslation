#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
	for(auto &e:u) fill_v<T>(e,v...);
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int64 N;
	cin >> N;
	vector<int64> A(3*N);
	auto dp = make_v<int64>(N, N);
	auto dp2 = make_v<int64>(N);
	fill_v<int64>(dp, -INF);
	fill_v<int64>(dp2, -INF);
	for (auto& x : A) {
	  cin >> x; x--;
	}

	using T = tuple<int, int, int>;
	dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
	dp2[A[0]] = dp2[A[1]] = 0;
	int64 sum = 0, mx = 0;
	for (int64 i = 2; i + 2 < 3*N; i += 3) {
    vector<T> upd;
	  int64 mx2 = 0;
	  if (A[i] == A[i+1] && A[i+1] == A[i+2]) {
	    sum += 1;
	    continue;
	  }
	  // 余ってる2つと3つのうちの1つが等しいときのやつ
	  REP(j, 3) {
	    upd.emplace_back(A[i+j], A[i+(j+1)%3], max(dp[A[i+(j+2)%3]][A[i+(j+2)%3]] + 1, mx));
      upd.emplace_back(A[i+(j+1)%3], A[i+j], max(dp[A[i+(j+2)%3]][A[i+(j+2)%3]] + 1, mx));
	    chmax(mx2, max(dp[A[i+(j+2)%3]][A[i+(j+2)%3]] + 1, mx));
	  }

	  // 余ってるうちの1つと3つのうちの2つ
	  REP(j, 3) {
	    REP(k, N) {
	      int score = (A[i+j] == A[i+(j+1)%3]);
	      upd.emplace_back(A[i + (j+2)%3], k, max(dp[A[i+j]][k] + score, dp2[k]));
        upd.emplace_back(k, A[i + (j+2)%3], max(dp[A[i+j]][k] + score, dp2[k]));
        chmax(mx2, dp[A[i+j]][k] + score);
	    }
	  }
	  for (auto &x : upd) {
	    int a, b, c;
	    tie(a, b, c) = x;
	    chmax(dp[a][b], c);
	    chmax(dp2[a], c);
	    chmax(dp2[b], c);
	  }
	  chmax(mx, mx2);
	}
	int64 res = 0;
	REP(i, N) {
	  REP(j, N) {
	    chmax(res, dp[i][j] + sum + (i == j && i == A.back()));
	  }
	}
	cout << res << endl;
}
