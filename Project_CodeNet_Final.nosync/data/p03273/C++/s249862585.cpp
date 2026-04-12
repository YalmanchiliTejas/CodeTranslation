#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REP1(i,n) for(int i = 1; i <= (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define ALL(a) begin(a), end(a)
#define CEIL(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))
#define X first
#define Y second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;

constexpr int MOD = int(1e9 + 7);
constexpr int INF = int(1e9 + 1);
constexpr ll LLINF = ll(4 * 1e18 + 1);
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);
	
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	REP(i, h) cin >> a[i];
	
	bool f = true;
	while(f){
		f = false;
		REP(i, h){
			bool flg = true;
			REP(j, w){
				if(a[i][0] != a[i][j] || a[i][j] == '#') {
					flg = false;
					break;
				}
			}
			if(flg){
				for(int j = i; j < h - 1; ++j){
					a[j] = a[j + 1];
				}
				--h;
				f = true;
			}
		}
		
		REP(i, w){
			bool flg = true;
			REP(j, h){
				if(a[0][i] != a[j][i] || a[j][i] == '#') {
					flg = false;
					break;
				}
			}
			if(flg){
				for(int j = 0; j < h; ++j){
					for(int k = i; k < w - 1; ++k){
						a[j][k] = a[j][k + 1];
					}
				}
				--w;
				f = true;
			}
		}
	}
	
	REP(i, h){
		REP(j, w){
			cout << a[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}
