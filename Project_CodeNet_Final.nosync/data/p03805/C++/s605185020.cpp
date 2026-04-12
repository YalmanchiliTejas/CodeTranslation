#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int N, M;
int G[10][10] = { 0 };
int ans = 0;
bool vis[10] = {false};


void dfs(int s) {
	vis[s] = true;
	
	REP(i, N) {
		bool F = true;

		if (G[s][i] && !vis[i]) {
			vis[i] = true;
			REP(i, N) {
				if (!vis[i])F = false;
			}
			if (F) {
				ans++;
				vis[i] = false;
				//cout << "K" << s << " " << i << endl;
			}
			else {
			//	cout << s << " " << i << endl;
				dfs(i);
			}
		}
	}
	vis[s] = false;
	return;
}






signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	cin >> N >> M;
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a][b]=1;
		G[b][a] = 1;
	}
	dfs(0);
	cout << ans << endl;

	return 0;
}

