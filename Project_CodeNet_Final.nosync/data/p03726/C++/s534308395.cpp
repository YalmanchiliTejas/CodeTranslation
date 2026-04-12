#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;

const int MAX_N = 1e5 + 10;
int N; ll Sum[MAX_N]; int Cnt[MAX_N];
vector<int> Ed[MAX_N];
bool Chk[MAX_N];
int main() {
	cin >> N;
	for(int i=1, x, y; i<N; i++) {
		scanf("%d%d", &x, &y);
		Ed[x].push_back(y); Sum[x] += y; Cnt[x]++;
		Ed[y].push_back(x); Sum[y] += x; Cnt[y]++;
	}
	queue<int> Q;
	for(int i=1; i<=N; i++) if(Cnt[i] == 1) Q.push(i);

	bool whiteWin = false;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		if(Chk[v]) continue;
		if(Cnt[v] == 0) {whiteWin = true; break;}
		int p = Sum[v];
		Cnt[p]--; Cnt[v]--; Sum[v] -= p; Sum[p] -= v;
		Chk[p] = Chk[v] = true;
		for(int w : Ed[p]) {
			if(Chk[w]) continue;
			Sum[w] -= p;
			Cnt[w]--;
			if(Cnt[w] == 1) Q.push(w);
		}
	}
	puts(whiteWin ? "First" : "Second");
	return 0;
}