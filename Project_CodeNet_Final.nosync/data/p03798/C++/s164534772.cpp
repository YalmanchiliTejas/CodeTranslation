#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define all(v) begin(v), end(v)
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;
const ll inf = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	
	vector<char> seq(N, '?');
	char which[] = { 'S', 'W' };

	rep(i, 2) {
		rep(j, 2) {
			seq = vector<char>(N, '?');
			seq[0] = which[i]; //SS,SW,WS,WWの4通り
			seq[1] = which[j];
			bool con = ((seq[0] == 'S' && ((seq[1] == 'S' && s[0] == 'o') || (seq[1] == 'W' && s[0] == 'x')))
				||
				(seq[0] == 'W' && ((seq[1] == 'S' && s[0] == 'x') || (seq[1] == 'W' && s[0] == 'o')))); //SかWの判定

			seq[N - 1] = (con) ? 'S' : 'W'; //0と1からn-1が分かる

			int seq_first = seq[0];
			int seq_last = seq[N - 1];

			REP(k, 1, N) {
				con = ((seq[k] == 'S' && ((seq[k - 1] == 'S' && s[k] == 'o') || (seq[k - 1] == 'W' && s[k] == 'x')))
					||
					(seq[k] == 'W' && ((seq[k - 1] == 'S' && s[k] == 'x') || (seq[k - 1] == 'W' && s[k] == 'o'))));
				seq[(k + 1) % N] = (con) ? 'S' : 'W'; //2~n-1,0まで求める
			}

			if (seq[0] == seq_first && seq[N - 1] == seq_last) { //最初と最後が変更前と同じか
				rep(i, N) {
					cout << seq[i];
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;

	return 0;
}