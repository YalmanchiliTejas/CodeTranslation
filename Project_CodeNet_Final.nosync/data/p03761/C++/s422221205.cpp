#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int n;
	cin >> n;
	int arr[n][26] = {0};
	/*REP(i, 0, n){
		REP(j, 0, 26) arr[i][j] = 0;
	}*/
	string tmp;
	REP(i, 0, n){
		cin >> tmp;
		for(char c: tmp) ++arr[i][c-'a'];
	}
	string ans = "";
	REP(i, 0, 26){
		int m = INT_MAX;
		REP(j, 0, n) m = min(m, arr[j][i]);
		REP(j, 0, m) ans += (i+'a');
	}
	cout << ans;

}
