#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<utility> //pair
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef vector<vector<int>> Graph;

int main() {
	//入力;
	int N, M;
	cin >> N >> M;
	Graph G(N);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		G[a - 1].push_back(b - 1);
		G[b - 1].push_back(a - 1);
	}

	//順列用のベクトル;
	vector<int> P;
	REP(i, N-1) P.push_back(i+1);

	//答え;
	ll ans = 0;

	//全順列探索;
	do {
		int startv, nextv;
		startv = 0;
		bool check1;
		bool check2 =true;

		REP(i, N - 1) {
			nextv = P[i];
			
			check1 = false;
			for (auto& x : G[startv]) { //始点からいける頂点の中にnextvが存在するか
				if (x == nextv) check1 = true;
			}

			if (!check1) { //ダメな場合はそこで探索終了;
				check2 = false;
				break;
			}

			startv = P[i];
		}

		if (check2) ++ans;
	} while (next_permutation(P.begin(), P.end()));

	cout << ans << endl;


	//小数点以下の桁数表示;
	//cout << fixed << setprecision(15);

	return 0;
}