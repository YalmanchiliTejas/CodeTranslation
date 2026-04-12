#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define INF 1e9

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
	int n;
	cin >> n;
	vi cou(26, INF);
	rep(i, 0, n) {
		string s;
		cin >> s;
		rep(j, 0, 26) {
			int a = count(all(s), 'a' + j);
			cou[j] = min(cou[j], a);
		}
	}
	string ans;
	rep(i, 0, 26) {
		char x = 'a' + i;
		rep(j, 0, cou[i]) {
			ans += x;
		}
	}
	cout << ans << endl;
}