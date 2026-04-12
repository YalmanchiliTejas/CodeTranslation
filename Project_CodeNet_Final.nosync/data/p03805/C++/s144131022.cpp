#pragma region Template
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define rng(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define rbf(i, v) for (auto& (i) : (v))
#define All(x) (x).begin(),(x).end()
#define cAll(x) (x).cbegin(),(x).cend()
#define COL(x) cout << x << endl
#define CO(x) cout << x
//#define int long long

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VP = vector<PII>;

const double PI = 3.141592653589793;
const int MOD = 1000000007;
const LL INF64 = INT64_MAX;
const int INF = INT_MAX;

inline int sqr(int x) { return (x * x); }
inline void printd(double x) { printf("%.10lf\n", x); }
inline void upsort(VI& x) { sort((x).begin(), (x).end()); }
inline void downsort(VI& x) { sort((x).begin(), (x).end(), greater<int>()); }
inline int absdiff(int a, int b) {
	if (b > a) return absdiff(b, a);
	return (a - b);
}
int gcd(int a, int b) { // 最大公約数
	if (a < b) return gcd(b, a);
	int r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
inline int lcm(int a, int b) { return a * b / gcd(a, b); } // 最小公倍数
#pragma endregion



signed main()
{	
	int N, M;
	cin >> N >> M;
	VP AB(M);
	rbf(ab, AB) cin >> ab.first >> ab.second;

	VI perm(N-1);
	int i = 2;
	rbf(p, perm) p = i++; // perm = {2, 3, ... , N}

	i = 2;
	int pattern = 1;
	while (i < N) pattern *= i++;

	// {2, 3, ... , N}の全並べ替えパターンをallpermに格納
	VVI allperm(pattern, VI(N - 1));
	i = 0;
	do {
		allperm[i++] = perm;
	} while (next_permutation(All(perm)));

	int a, b, cnt = 0;
	bool flg = false, flg2 = false;
	// 全並べ替えパターンについて辺を辿ることができるかを判定
	rbf(pp, allperm) {
		a = 1; b = 1;
		flg2 = true;
		rbf(p, pp) {		
			a = b;
			b = p;
			flg = false;
			rbf(ab, AB) {
				// a, bをつなぐ辺があるかの判定
				if ((a == ab.first && b == ab.second) || (b == ab.first && a == ab.second)) {
					flg = true;
					break;
				}
			}
			// a, bをつなぐ辺がなければありえないパスなのでbreak
			if (!flg) {
				flg2 = false;
				break;
			}
		}
		// rbf(p, pp)を完走できればあり得るパスなのでカウント追加
		if (flg2) {
			cnt++;
		}
	}

	COL(cnt);

	return 0;
}