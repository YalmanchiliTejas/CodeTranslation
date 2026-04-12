#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//
//template<class T> using Tree = tree<T, null_type, less<T>, rb_t_tag,t_order_statistics_node_update>;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;
//const long long mod = 998244353;

// watch this
//using ll = long long;
//typedef long long LL;
#define ll long long
#undef ll

const int mxN = 3010;

long long md;
long long pow_mod(long long base, long long power) {
	long long res = 1;
	while (power) {
		if (power & 1)
			res = res * base % md;
		base = base * base % md;
		power >>= 1;
	}
	return res;
}

long long st[mxN][mxN];
long long NcR[mxN][mxN];
long long p2[mxN], p2e[mxN];

void init() {
	NcR[0][0] = 1;
	st[0][0] = 1;
	p2[0] = p2e[0] = 1;
	for (int i = 1; i < mxN; i++) {
		NcR[i][0] = 1;
		st[i][0] = 1;
		p2[i] = (p2[i - 1] << 1) % md;
		p2e[i] = (p2e[i - 1] << 1) % (md - 1);
		for (int j = 1; j <= i; j++) {
			NcR[i][j] = (NcR[i - 1][j] + NcR[i - 1][j - 1]) % md;
			st[i][j] = ((j + 1) * st[i - 1][j] + st[i - 1][j - 1]) % md;
		}
	}
}

long long get(long long N, long long ch) {
	long long num = NcR[N][ch];
	long long ac = 0;
	for (int i = 0; i <= ch; i++) {
		ac = (ac
				+ (st[ch][i] * pow_mod(p2[N - ch], i) % md)
						* pow_mod(2, p2e[N - ch])) % md;
	}
	return num * ac % md;
}

int main(int argc, char** argv) {
	//#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//#endif

	int N;
	cin >> N >> md;
	init();
	long long res = 0;
	for (int i = 0; i <= N; i++) {
		res = (res + md + (i & 1 ? -1 : 1) * get(N, i)) % md;
//		cerr << (i & 1 ? -1 : 1) * get(N, i) << '\n';
	}
	cout << res << '\n';
	return 0;
}
