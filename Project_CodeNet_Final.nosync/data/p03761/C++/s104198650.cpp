#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int n;
string s[50];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	rep(i, 0, n) cin >> s[i];

	map<char, int> m[n];
	rep(i, 0, n) {
		rep(j, 0, s[i].size()) {
			m[i][s[i][j]]++;
		}
	}

	string res = "";
	map<char, int> tmp;
	map<char, int> used;
	rep(j, 0, 26) tmp[char('a' + j)] = 51;
	rep(i, 0, n) rep(j, 0, 26) {
		tmp[char('a' + j)] = min(tmp[char('a' + j)], m[i][char('a' + j)]);
		used[char('a' + j)]++;
	}

	rep(i, 0, 26) {
		int num = tmp[char('a' + i)];
		if(used[char('a' + i)] == n) {
			rep(j, 0, num) {
				res += char('a' + i);
			}
		}
	}

	cout << res << endl;

}
