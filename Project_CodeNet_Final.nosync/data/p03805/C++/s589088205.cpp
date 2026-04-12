#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 12;

bool g[MAX][MAX];

int main(){ _

	int N, M;
	cin >> N >> M;

	memset(g, 0, sizeof g);

	while(M--){
 		int x,y;
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}

	vector<int> V;
	for(int i = 1; i <= N; i++) V.pb(i);

	int ans = 0;

	do{
		if(V[0] != 1) continue;

		bool ok = 1;

		for(int i = 1; i < N; i++){
			ok &= g[V[i]][V[i-1]];
		}
		
		ans += ok;

	} while(next_permutation(all(V)));

	cout << ans << endl;

	return 0;
}
