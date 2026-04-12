#include "bits/stdc++.h"
using namespace std;

//諸機能
#pragma region MACRO 
#define putans(x)  std::cerr << "[ answer ]: " ; cout << (x) << endl
#define dputans(x) std::cerr << "[ answer ]: "; cout << setprecision(40) << (double)(x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define RREP(i,n,a) for(int i=(int)(n-1); i>= a; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define all(a) begin((a)),end((a))
#define mp make_pair
#define exist(container, n) ((container).find((n)) != (container).end())
#define equals(a,b) (fabs((a)-(b)) < EPS)
#ifdef _DEBUG //ファイルからテストデータを読み込む
std::ifstream ifs("data.txt");
#define put ifs >>
#else //ジャッジシステムでいい感じにやる
#define put cin >>
#endif
#pragma endregion
//デバッグなどの支援
#pragma region CODING_SUPPORT
#ifdef _DEBUG
#define dbg(var0) { std::cerr << ( #var0 ) << "=" << ( var0 ) << endl; }
#define dbg2(var0, var1) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg(var1); }
#define dbg3(var0, var1, var2) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg2(var1, var2); }
#define dbgArray(a,n) {std::cerr << (#a) << "=";  rep(i,n){std::cerr <<(a[i])<<",";} cerr<<endl;} 
#else
#define dbg(var0) {}
#define dbg2(var0, var1) {}
#define dbg3(var0, var1, var2) {}
#define dbgArray(a,n) {}
#endif 
#pragma endregion 
//typedef（書き換える、書き足す可能性ある）
#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii; typedef pair<string, string> pss; typedef pair<int, string>pis;
typedef pair<long long, long long> pll;
typedef vector<string> vs; typedef vector<int> vi;
#pragma endregion
//諸々の定数(書き換える可能性ある)
#pragma region CONST_VAL
#define PI (2*acos(0.0))
#define EPS (1e-10)
#define MOD (ll)(1e9 + 7)
#define INF (ll)(2*1e9)
#pragma endregion






int main() {
	int h, w; put h >> w;
	char map[9][9];
	int num = 0;
	rep(i, h) {
		string s; put s;
		rep(j, w) {
			if (s[j] == '#') {
				map[i][j] = '#';
				num++;
			}
			else {
				map[i][j] = '.';
			}
		}
	}
	if (num != ( h + w - 1)) {
		putans("Impossible");
		goto END;
	}
	else {
		int x = 0;
		int y = 0;
		while (x < w-1 || y < h-1) {
			if (x < w-1 && map[y][x+1] == '#') {
				x++;
			}
			else if (y < h-1 && map[y+1][x] == '#') {
				y++;
			}
			else {
				putans("Impossible");
				goto END;
			}
			dbg2(x, y);
		}
		putans("Possible");
	}
END:
	return 0;
}