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



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N;
	string S;
	cin >> N >> S;

	
	int ans[4][100010];
	ans[0][0] = 1;
	ans[0][1] = 1;

	ans[1][0] = 1;
	ans[1][1] = 0;
	
	ans[2][0] = 0;
	ans[2][1] = 1;
	
	ans[3][0] = 0;
	ans[3][1] = 0;


	REP(k, 4) {
		bool F = false,FF=false;
		FOR(i,1, N) {
			if (i == N - 1) {
				if (S[i] == 'o' && ans[k][i] == 1 && ans[k][i - 1] == ans[k][0]) F = true;
				if (S[i] == 'x' && ans[k][i] == 0 && ans[k][i - 1] == ans[k][0]) F = true;
				if (S[i] == 'o' && ans[k][i] == 0 && ans[k][i - 1] != ans[k][0]) F = true;
				if (S[i] == 'x' && ans[k][i] == 1 && ans[k][i - 1] != ans[k][0]) F = true;

				if (S[0] == 'o' && ans[k][i] == ans[k][1] && ans[k][0] == 1)FF = true;
				if (S[0] == 'o' && ans[k][i] != ans[k][1] && ans[k][0] == 0)FF = true;
				if (S[0] == 'x' && ans[k][i] != ans[k][1] && ans[k][0] == 1)FF = true;
				if (S[0] == 'x' && ans[k][i] == ans[k][1] && ans[k][0] == 0)FF = true;
			}
			if (F && FF) {
				//cout << k << endl;
				REP(j, N) {
					if (ans[k][j] == 1)cout << "S";
					else cout << "W";
				}
				cout << endl;
				return 0;
			}
			
			if (S[i] == 'x' && ans[k][i] == 1) {
				if (ans[k][i - 1] == 1) ans[k][i + 1] = 0;
				else ans[k][i + 1] = 1;
			}
			else if (S[i] == 'o' && ans[k][i] == 0) {
				if (ans[k][i - 1] == 1) ans[k][i + 1] = 0;
				else ans[k][i + 1] = 1;
			}
			else
				ans[k][i + 1] = ans[k][i - 1];
		}
	}

	cout << -1 << endl;
	return 0;
}

