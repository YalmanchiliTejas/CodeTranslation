#include <bits/stdc++.h>
#define P 1000000007

using namespace std;

typedef long long ll;

int n, m;

char ch[400010];

ll powmod(ll x, ll y = P - 2, ll p = P) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ans;
}

ll F[400010][2][2], G[400010][2][2], H[400010], SH[400010], SG[400010][2][2];

// G1 : ABABABA
// G2 : BABABAB

void cmin(int &x, int y) {if(x > y) x = y;}

void add(ll &x, ll y) {x = (x + y) % P;}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", ch + 1);
	ll ans = 0;
	// qingyise
	int sub1 = 1;
	for(int i = 2; i <= m; i++) if(ch[i] != ch[1]) sub1 = 0;
	if(sub1 == 1) {
		F[0][0][0] = 1;
		F[0][1][1] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 2; j++) {
				F[i][j][0] = (F[i - 1][j][0] + F[i - 1][j][1]) % P;
				F[i][j][1] = (F[i - 1][j][0]) % P;
			}
		ans = (F[n][0][0] + F[n][1][1]) % P;
		printf("%lld\n", (ans % P + P) % P);
		return 0;
	}
	if(n % 2 == 1) {
		puts("0");
		return 0;
	}
	vector <int> V(1, 1);
	for(int i = 2; i <= m; i++) if(ch[i] == ch[i - 1]) V.back()++; else V.push_back(1);
	int l = 0, r = 0, mnA = n + 5, mnB = n + 5, nw = 0;
	for(int i = 1; i < V.size(); i += 2) {
		if(V[i] % 2 == 1) nw ^= 1;
		if(i + 2 != V.size() && V[i + 1] % 2 == 1) {
			if(nw == 0) cmin(mnA, V[i + 1]); else cmin(mnB, V[i + 1]);
		}
	}
	cmin(mnA, V[0] + !(V[0] % 2));
	H[1] = 1, SH[1] = 1;
	for(int i = 3; i <= n + 1; i += 2) {
		H[i] = SH[i - 2];
		if(i >= min(mnA, mnB) + 3) {
			add(H[i], -SH[i - (min(mnA, mnB) + 3)]);
		}
		//H[i] = -H[i];
		SH[i] = (H[i] + SH[i - 2]) % P;
	}
	for(int i = 1; i <= n; i += 2) {
		//if(n - i <= mnA) add(ans, G[i][1][1] * (n - i + 1));
		//if(n - i <= mnB) add(ans, G[i][0][0] * (n - i + 1));
		if(n - i <= min(mnA, mnB)) add(ans, H[i] * (n - i + 1));
	}
	printf("%lld\n", (ans % P + P) % P);
	return 0;
}