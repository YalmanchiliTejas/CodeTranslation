#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, m;
// vector<int> G[100];
int G[10][10];

int main(void){
	cin >> n >> m;
	rep(i, m){
		int a, b; cin >> a >> b;
		a--; b--;
		// G[a].pb(b);
		// G[b].pb(a);
		G[a][b] = G[b][a] = 1;
	}

	// 0してん
	vector<int> v(n - 1);
    reps(i, 1, n) v[i - 1] = i;
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        int now = 0;
        rep(i, v.size()){
        	if(G[now][v[i]] == 0) break;
      		now = v[i];
        	if(i == v.size() - 1){
        		ans++;
	        	/*printf("k\n");
	        	rep(i, v.size()){
	        		printf("%d ", v[i]);
	        	}
	        	printf("\n");
	        	*/
	        	}
	        	
        }
    }while(next_permutation(v.begin(), v.end()));
    printf("%d\n", ans);
	return 0;
}
