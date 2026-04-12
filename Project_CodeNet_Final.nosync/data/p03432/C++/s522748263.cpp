// A code file. By Tiger3018
// Created  Time 2019/03/07 11:20:57
// Last Modified 2019/03/08 16:36:40
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define _for(a,b,c) for(int a=(b),a##lim=(c);a<=a##lim;a++)
#define _rof(a,b,c) for(int a=(b),a##lim=(c);a>=a##lim;a--)
typedef long long ll;
using namespace std;

const int p = 998244353;
int n, m;

namespace BAO {
	int f[209][8009], rev[20009], yua[15][2], NTy = 3,
		a[20009], b[20009], siz, DTT, jie[8009], jinv[8009];

	int ppo(int a, int b) {
		int c = 1;
		while(b) {
			if(b & 1) c = (ll)c * a % p;
			a = (ll)a * a % p;
			b >>= 1;
		}
		return c;
	}
	void add(int &a, ll b) {a = (a + b >= p) ? (a + b - p) : (a + b);}
	void init() {
		jie[0] = jie[1] = jinv[0] = jinv[1] = 1; 
		siz = log2(n * 2) + 1; memset(f, 0, sizeof f);
		rev[0] = 0; f[0][0] = 1;
		DTT = ppo((1 << siz), p - 2);
		_for(i, 0, 1 << siz) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (siz - 1));
		}
		_for(i, 1, 14) {
			yua[i][0] = ppo(NTy, (p - 1) / (1 << i));
			yua[i][1] = ppo(yua[i][0], p - 2);
		}
		_for(i, 2, n + 2) jie[i] = (ll)jie[i - 1] * i % p;
		_for(i, 2, n + 2) jinv[i] = (ll)jinv[p % i] * (p - p / i) % p;
		_for(i, 1, n + 2) jinv[i] = (ll)jinv[i - 1] * jinv[i] % p;
	}
	void NTT(int *li, bool inv) {
		int si = (1 << siz) - 1, gen, t1, t2;
//		fprintf(stderr, "!%d %d\n", si, siz);
		_for(i, 0, si) if(i < rev[i]) { swap(li[i], li[rev[i]]); }
		_for(i, 1, siz) {
			gen = yua[i][inv];
			for(int l = 0; l <= si; l += (1 << i)) {
				for(int k = 0, klim = (1 << (i - 1)), mu = 1; k < klim; k ++) {
//					fprintf(stdout, "%d %d\n", l + k, l + k + klim);
					t1 = li[l + k]; t2 = (ll)mu * li[l + k + klim] % p;
					li[l + k] = ((ll)t1 + t2) % p;
					li[l + k + klim] = ((ll)t1 - t2 + p) % p;
					mu = (ll)mu * gen % p;
				}
			}
//			_for(i, 0, si) printf("%d ", li[i]);
//			printf("?\n %d\n", gen);
		}
		if(inv) {
			_for(i, 0, si) li[i] = (ll)li[i] * DTT % p;
		}
	}
	void solve() {
		init(); int res = 0;
		_for(i, 1, m) {
			f[i][0] = f[i - 1][0];
			_for(j, 1, n) {
				f[i][j] = f[i - 1][j] * (1 + (ll)jie[j + 1] * jinv[2] % p * jinv[j - 1] % p) % p;
			}
			_for(k, n + 1, (1 << siz) - 1) a[k] = b[k] = 0;
			_for(k, 0, n) a[k] = (ll)f[i - 1][k] * jinv[k] % p;
			_for(k, 1, n) b[k] = jinv[k + 2];
			b[0] = 0;
//			_for(x, 1, n) {printf("%d ", b[x - 1]);} printf(")\n", siz);
//			_for(x, 1, n) {printf("%d ", b[x - 1]);} printf("(\n", siz);
			NTT(a, 0); NTT(b, 0);
//			_for(x, 1, n) {printf("%d ", b[x - 1]);} printf("!\n", siz);
//			_for(x, 1, n) {printf("%d ", b[x - 1]);} printf("!\n", siz);
			_for(k, 0, (1 << siz) - 1) a[k] = (ll)a[k] * b[k] % p;
//			_for(x, 1, n) {printf("%d ", a[x - 1]);} printf(")\n", siz);
			NTT(a, 1);
//			_for(x, 1, n) {printf("%d ", a[x - 1]);} printf(")\n", siz);
//			_for(x, 0, n) {printf("%d(%d ", f[i][x], jie[x + 2]);} printf("(%d)\n", siz);
			_for(j, 1, n) add(f[i][j], (ll)a[j] * jie[j + 2] % p);
//			_for(x, 0, n) {printf("%d ", f[i][x]);} printf("(%d)\n", siz);
		}
		_for(i, 0, n) add(res, (ll)f[m][i] * jie[n] % p * jinv[i] % p * jinv[n - i] % p);
		printf("%d\n", res);
	}
}

int main(){
	int opt;
	scanf("%d%d", &n, &m);
/*	if(opt == 2) {BAO::solve();}
	else if(opt == 1) {NS2::solve();}
	else */{BAO::solve();}
	return 0;
}
