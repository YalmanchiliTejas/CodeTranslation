#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
	ll N, M;
	cin >> N >> M;
	ll graph[N][N];
	REP(i, N)REP(j, N) graph[i][j] = 0;
	REP(i, M){
		ll a, b;
		cin >> a >> b;
		a--;b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	vector<ll> perm(N);
	REP(i, N) perm[i] = i;
	bool flag = true;
	ll res = 0;
	while(flag){
		bool path = true;
		REP(i, N-1){
			if(graph[perm[i]][perm[i+1]]==0) path = false;
		}
		if(perm[0]==0) res += path;
		flag= next_permutation(perm.begin(), perm.end());
	}
	cout << res << endl;
    return 0;
}