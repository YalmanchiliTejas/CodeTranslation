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
typedef vector<ll> VI;
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
//do {
//    print(v);
//  } while (std::next_permutation(v.begin(), v.end()));


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,W;
	cin >> H>>W;
	int cnt = 0;
	REP(i, H) {
		REP(j, W) {
			char S;
			cin >> S;
			if (S == '#')cnt++;
		}
	}
	if (cnt == H + W -1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}


















