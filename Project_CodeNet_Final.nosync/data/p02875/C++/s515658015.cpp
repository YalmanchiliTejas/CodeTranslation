#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int const N = 5000000, md = 998244353;
int p2[N + 1], fc[N + 1], inv[N + 1], fcin[N + 1];

void ad(int &x, int y) { if ((x += y) >= md)x-= md; }
int ch(int n, int r) { return (ll)fc[n] * fcin[r] % md * fcin[n - r] % md; }

int main(){
	int n;
	scanf("%d", &n);
	n >>= 1;
	
	fc[0] = 1;
	f(i, 1, n + 1)fc[i] = (ll)fc[i - 1] * i % md;
	inv[1] = 1;
	f(i, 2, n + 1)inv[i] = md - md / i * (ll)inv[md % i] % md;
	fcin[0] = 1;
	f(i, 1, n + 1)fcin[i] = (ll)fcin[i - 1] * inv[i] % md;
	p2[0] = 1;
	f(i, 1, n + 1)ad(p2[i] = p2[i - 1], p2[i - 1]);
	
	int an = 0, s = 0;
	f(i, 1, n + 1){
		ad(s, (ll)ch(n, i - 1) * p2[i - 1] % md);
		ad(an, (ll)p2[n - i] * ch(n, i) % md * s % md);
	}
	ad(an, an);
	int z = 1;
	f(i, 0, n << 1)z = (ll)z * 3 % md;
	ad(z, md - an);
	printf("%d\n", z);
}