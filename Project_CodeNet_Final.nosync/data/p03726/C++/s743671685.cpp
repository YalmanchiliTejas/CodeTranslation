#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, a, b;
vector<int>v[100000];
bool vis[100000];

int dfs(int x) {
	vis[x] = true;
	int cnt0, cnt1;
	cnt0 = cnt1 = 0;
	for (int i : v[x]) {
		if (!vis[i]) {
			int t = dfs(i);
			if (t == 0xE869120)return 0xE869120;
			if (t) {
				++cnt1;
			}
			else {
				++cnt0;
			}
		}
	}
	if (cnt1 >= 2) {
		return 0xE869120;
	}
	else if (cnt1 == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> a >> b;
		--a;
		--b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int t = dfs(0);
	if (t == 0xE869120 || (t == 1 && N % 2 == 1)) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
}