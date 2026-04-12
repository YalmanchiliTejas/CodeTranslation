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

const int MOD = 1e9 + 7, MAX_N = 1e3 + 10;

int N, A, B, C, D;
int Dy[MAX_N][MAX_N], F[MAX_N], Fi[MAX_N];

void add(int &a, int b) {if((a+=b) >= MOD) a-=MOD;}
void mul(int &a, int b) {a = 1ll * a * b % MOD;}
int atob(int a, int b) {
	int res = 1, p = a;
	while(b) {
		if(b%2) mul(res, p);
		mul(p, p);
		b /= 2;
	}
	return res;
}
int inv(int a) {return atob(a, MOD-2);}

int main() {
	cin >> N >> A >> B >> C >> D;
	F[0] = 1; for(int i=1; i<=N; i++) F[i] = F[i-1], mul(F[i], i);
	for(int i=0; i<=N; i++) Fi[i] = inv(F[i]);

	Dy[A-1][0] = 1;
	for(int a=A; a<=B; a++) {
		for(int n=0; n<=N; n++) {
			add(Dy[a][n], Dy[a-1][n]);
			for(int k=C; k<=D && n-a*k>=0; k++) {
				int val = Dy[a-1][n-a*k];
				mul(val, Fi[k]);
				mul(val, atob(Fi[a], k));
				mul(val, F[n]);
				mul(val, Fi[n-a*k]);
				add(Dy[a][n], val);
			}
		}
	}
	printf("%d\n", Dy[B][N]);
	return 0;
}
