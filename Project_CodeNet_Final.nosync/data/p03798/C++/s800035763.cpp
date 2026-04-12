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
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000
bool sheep[100000];
int N;
string s;

void output() {
	rep(i, 0, N) {
		if(sheep[i]) cout << 'S' ;
		else cout << 'W'; 
	}
	cout << endl;
}

bool check() {
	if(sheep[0]) {
		if(s[0] == 'o') {
			if(sheep[1] != sheep[N - 1]) return false;
		} else {
			if(sheep[1] == sheep[N - 1]) return false;
		}
	} else {
		if(s[0] == 'o') {
			if(sheep[1] == sheep[N - 1]) return false;
		} else {
			if(sheep[1] != sheep[N - 1]) return false;
		}
	}
	rep(i, 1, N - 1) {
		if(sheep[i]) {
			if(s[i] == 'o') {
				if(sheep[i + 1] != sheep[i - 1]) return false;
			} else {
				if(sheep[i + 1] == sheep[i - 1]) return false;
			}
		} else {
			if(s[i] == 'o') {
				if(sheep[i + 1] == sheep[i - 1]) return false;
			} else {
				if(sheep[i + 1] != sheep[i - 1]) return false;
			}
		}
	}

	if(sheep[N - 1]) {
		if(s[N - 1] == 'o') {
			if(sheep[N - 2] != sheep[0]) return false;
		} else {
			if(sheep[N - 2] == sheep[0]) return false;
		}
	} else {
		if(s[N - 1] == 'o') {
			if(sheep[N - 2] == sheep[0]) return false;
		} else {
			if(sheep[N - 2] != sheep[0]) return false;
		}
	}
	return true;
}

void solve() {
	rep(i, 1, N) {
		if(sheep[i]) {
			if(s[i] == 'o') sheep[i + 1] = sheep[i - 1];
			else sheep[i + 1] = !sheep[i - 1];
		} else {
			if(s[i] == 'o') sheep[i + 1] = !sheep[i - 1];
			else sheep[i + 1] = sheep[i - 1];
		}
	}
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> s;
	memset(sheep, false, sizeof(sheep));
	sheep[0] = true;
	if(s[0] == 'o') {
		sheep[N - 1] = sheep[1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
		memset(sheep, false, sizeof(sheep));
		sheep[0] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
	} else {
		sheep[1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
		memset(sheep, false, sizeof(sheep));
		sheep[0] = true;
		sheep[N - 1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
	}

	memset(sheep, false, sizeof(sheep));
	if(s[0] == 'o') {
		sheep[1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
		memset(sheep, false, sizeof(sheep));
		sheep[N - 1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
	} else {
		sheep[1] = true;
		sheep[N - 1] = true;
		solve();
		if(check()) {
			output();
			return 0;
		}
		memset(sheep, false, sizeof(sheep));
		solve();
		if(check()) {
			output();
			return 0;
		}
	}

	cout << -1 << endl;

}
