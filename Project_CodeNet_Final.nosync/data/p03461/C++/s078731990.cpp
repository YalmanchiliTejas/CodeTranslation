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

const int MAX_A = 11;
const int MAX_N = 2e2 + 10;

int A, B, Nr[MAX_A][MAX_A];


const int ITER = 100;
int N = 2*ITER + 2;
vector<pi> Ed[MAX_N];
int Ans[ITER+1][ITER+1];
int main() {
	cin >> A >> B;
	for(int i=1; i<=A; i++) for(int j=1; j<=B; j++) scanf("%d", &Nr[i][j]);
	for(int i=1; i<=ITER; i++) Ed[i].emplace_back(i+1, 'X'+1000);
	for(int i=ITER+2; i<N; i++) Ed[i].emplace_back(i+1, 'Y'+1000);
	
	for(int i=0; i<=ITER; i++) for(int j=0; j<=ITER; j++) {
		int val = 0;
		for(int a=1; a<=A; a++) for(int b=1; b<=B; b++)
			val = max(Nr[a][b] - a*i - b*j, val);
		Ans[i][j] = val;
		//printf("%d %d : %d\n", i, j, val);
		if(val >= 0 && val <= 100)
			Ed[i+1].emplace_back(N-j, val);
	}

	for(int a=1; a<=A; a++) for(int b=1; b<=B; b++) {
		int now = INF;
		for(int i=0; i<=ITER; i++) for(int j=0; j<=ITER; j++) {
			int val = Ans[i][j]; 
			if(val >= 0 && val <= 100) now = min(now, val + a*i + b*j);
		}
		if(now != Nr[a][b]) return puts("Impossible") < 0;
	}
	puts("Possible");
	int M = 0; 
	for(int i=1; i<=N; i++) M += SZ(Ed[i]);
	printf("%d %d\n", N, M);
	for(int v=1; v<=N; v++) {
		for(auto &val : Ed[v]) {
			int w, c; tie(w, c) = val;
			if(c >= 1000) printf("%d %d %c\n", v, w, c - 1000);
			else printf("%d %d %d\n", v, w, c);
		}
	}
	printf("%d %d\n", 1, N);
	return 0;
}
