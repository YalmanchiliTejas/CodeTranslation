#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 1e5 + 50;
VI e[MAXN];
int cnt[MAXN];
bool first = false;

bool DFS(int x, int p = 0) {
	if(SZ(e[x]) == 1) return true;
	int cnt = 0;
	for(int u : e[x]) {
		if(u == p) continue;
		if(DFS(u, x)) cnt++;
	}
	if(cnt >= 2) first = true;
	if(cnt == 0) return true;
	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].PB(b);
		e[b].PB(a);
	}
	for(int i = 1; i <= N; i++)
		if(SZ(e[i]) > 1) {
			if(DFS(i))
				first = true;
			break;
		}
	puts(first ? "First" : "Second");
	return 0;
}
