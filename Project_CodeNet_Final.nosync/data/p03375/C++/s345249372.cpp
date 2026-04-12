#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e3 + 100;

ll mypow(ll a, ll b, ll m) {
	a %= m;
	ll r=1%m, p=a;
	while(b) {
		if(b%2) r=r*p%m;
		p=p*p%m;
		b>>=1;
	}
	return r;
}
int N, M;
ll C[MAX_N][MAX_N];
ll Dy[MAX_N][MAX_N];
void add(ll &a, ll b, ll m) {
	b %= m;
	a+=b;
	if(a>m) a-=m;
	if(a<0) a+=m;
}
int main() {
	cin >> N >> M;
	for(int i=0, j; i<=N; i++) for(C[i][0] = 1%M, j=1; j<=i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
	for(int i=0, j; i<=N; i++) for(Dy[i][0] = 1%M, j=1; j<=i; j++) Dy[i][j] = (Dy[i-1][j-1] + Dy[i-1][j] * (j+1)) % M;

	ll ans = mypow(2, mypow(2, N, M-1), M);
	for(int k=1; k<=N; k++) {
		ll sum = 0, mul0 = 1, mulbase = mypow(2, mypow(2, N-k, M-1), M) % M;
		ll mul0_to = mypow(2, N-k, M);
		for(int i=0; i<=k; i++) {
			ll now = Dy[k][i] % M;
			now = now * mul0 % M;
			mul0 = mul0 * mul0_to % M;
			now = now * mulbase % M;
			//printf("%d %d : %d * %d * %d\n", k, i, Dy[k][i], mypow(mypow(2, N-k, M), i, M) % M, mypow(2, mypow(2, N-k, M-1), M) % M);
			add(sum, now, M);
		}
		add(ans, C[N][k] * sum % M * (k % 2 == 1 ? -1 : 1), M);
	}
	printf("%lld\n", ans);
	return 0;
}


