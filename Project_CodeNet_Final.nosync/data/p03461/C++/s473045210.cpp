#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int oo = 1e9;
const int MOD = 1000000007;
const int BASE = 26;
const int N = 200011;

#define pb push_back
#define mp make_pair

int f[110][110], d[11][11], A, B, cnt = 1, S, T, fx[110], fy[110];
vector< pair<int, pii> > E;
void addEdge(int u , int v , int w) {
	E.pb(mp(w, mp(u, v)));
}
int main() {
	cin >> A >> B;
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B ; ++j) {
			scanf("%d", &d[i][j]);
		}
	}
	for (int x = 0 ; x <= 100 ; x++) {
		for (int y = 0 ; y <= 100 ; y++) {
			f[x][y] = -oo;
			for (int i = 1; i <= A; ++i) {
				for (int j = 1; j <= B ; ++j) {
					f[x][y] = max(f[x][y], d[i][j] - i * x - j * y);
				}
			}
		}
	}
	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B ; ++j) {
			int mn = 1e9;
			for (int x = 0 ; x <= 100 ; x++) {
				for (int y = 0 ; y <= 100 ; y++) {
					if (f[x][y] < 0)continue;
					mn = min(mn, f[x][y] + x * i + y * j);
				}
			}
			if (mn != d[i][j]) {
				puts("Impossible");
				return 0;
			}
		}
	}

	for (int i = 0 ; i <= 100 ; ++i) {
		fx[i] = cnt++;
		if (i > 0)
			addEdge(fx[i - 1], fx[i], -1);	
	}
	for (int i = 0 ; i <= 100 ; ++i) {
		fy[i] = cnt++;
		if (i > 0)
			addEdge(fy[i - 1], fy[i], -2);
	}			
	for (int x = 0 ; x <= 100 ; x++) {
		for (int y = 0 ; y <= 100 ; y++) {
			if (f[x][y] < 0)continue;
			addEdge(fx[x],fy[100-y],f[x][y]);
		}
	}
	puts("Possible");
	printf("%d %d\n", cnt - 1, (int)E.size() );
	for (int i = 0; i < E.size(); ++i){
		if(E[i].first == -1){
			printf("%d %d %c\n",E[i].second.first,E[i].second.second,'X');
		}else if(E[i].first == -2){
			printf("%d %d %c\n",E[i].second.first,E[i].second.second,'Y');
		}else{
			printf("%d %d %d\n",E[i].second.first,E[i].second.second,E[i].first );
		}
	}
	printf("%d %d\n",fx[0],fy[100]);
	return 0;
}
