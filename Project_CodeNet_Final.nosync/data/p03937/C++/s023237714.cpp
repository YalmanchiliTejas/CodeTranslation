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

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

int32 dx[4] = {-1, 0, 0, 1};
int32 dy[4] = {0, -1, 1, 0};

int main(void){
	int32 H, W;
	cin >> H >> W;
	string f[10];
	REP(i, H){
		cin >> f[i];
	}
	auto in = [&](int32 y, int32 x){
		return 0<=y && y < H && 0 <= x && x < W;
	};
	function<bool(PII, PII)> dfs = [&](PII pos, PII p){
		int32 cnt = 0;
		REP(i, 4){
			int32 yy = pos.fs+dy[i], xx = pos.sc+dx[i];
			if(!in(yy, xx)) continue;
			if(f[yy][xx] == '#') cnt++;
		}
		if((pos == PII(0, 0) || pos == PII(H-1, W-1)) && (cnt == 0 || cnt > 1)){
			return false;
		}else if(cnt > 2){
			return false;
		}
		if(pos == PII(H-1, W-1) && cnt == 1) return true;

		bool res = 0;
		REP(i ,4){
			int32 yy = pos.fs+dy[i], xx = pos.sc+dx[i];
			if(!in(yy, xx) || PII(yy, xx) == p) continue;
			if(f[yy][xx] == '#'){
				if(i <= 1) return false;
				res |= dfs(PII(yy, xx), pos);
			}
		}
		return res;
	};
	if(dfs(PII(0, 0), PII(-1, -1))){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
}