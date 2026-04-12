#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cmath>
#include <string> // これがないとstringの出力がエラー
#include <sstream>
#include <algorithm>
#include <bitset>
#include <list>
#include <set>
using namespace std;

typedef long long ll;

void flip(string& str, int n) {
	str[n] = '0';
	str[n + 1] = '1';
	str[n + 2] = '0';
}

map<string,ll> dp;
ll dfs(string str, ll cnt)
{
	if (dp.count(str) != 0) {
		return dp[str];
	}
	//cerr << str << " " << cnt << endl;
	ll maximum = 0;
	for (int i = 0; i < str.size() - 2; ++i) {
		if (i + 2 >= str.size()) continue;
		if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '1') {
			string next = str;
			flip(next, i);
			maximum = max(maximum, dfs(next, cnt + 1));
		}
	}
	ll ret = max(cnt, maximum);
	dp[str] = ret;
	return ret;
}

void pA()
{
	string str; cin >> str;
	for (int i = 0; i < str.size() - 1; ++i) {
		if (str[i] == 'A' && str[i + 1] == 'C') {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

void pB()
{
	int H, W; cin >> H >> W;
	vector<string> mp(H);
	for (auto& m : mp)
		cin >> m;

	int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (mp[i][j] == '.') {
				int cnt = 0;
				for (int k = 0; k < 8; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= H) continue;
					if (nx < 0 || nx >= W) continue;
					if (mp[i + dy[k]][j + dx[k]] == '#')
						cnt++;
				}
				mp[i][j] = '0' + cnt;
			}
		}
	}

	for (auto m : mp)
		cout << m << endl;
}

unsigned bit_count(unsigned n)
{
	unsigned i = 0;

	while (n) {
		i += n & 1;
		n >>= 1;
	}

	return i;
}

int N, M;
set<int> path[100004];

ll addPath()
{
	ll cnt = 0;
	for (int n0 = 1; n0 <= N; ++n0) {
		for (auto n1 : path[n0]) {
			if (n0 == n1) continue;
			for (auto n2 : path[n1]) {
				if (n1 == n2) continue;
				if (n0 == n2) continue;
				for (auto n3 : path[n2]) {
					if (n2 == n3) continue;
					if (n1 == n3) continue;
					if (n0 == n3) continue;
					if (path[n0].find(n3) == path[n0].end()) {
						cnt++;
						path[n0].insert(n3);
						path[n3].insert(n0);
					}
				}
			}
		}
	}
	return cnt;
}

void pC()
{
	cin >> N >> M;
	for (int m = 0; m < M; ++m) {
		int a, b; cin >> a >> b;
		path[a].insert(b);
		path[b].insert(a);
	}

	cout << addPath() << endl;
}

void pD()
{
	int N, K; cin >> N >> K;
	vector< pair<ll, ll> > pt1(N), pt2(N);
	for (int i = 0; i < N; ++i) {
		cin >> pt1[i].first >> pt1[i].second;
		pt2[i].first = pt1[i].second;
		pt2[i].second = pt1[i].first;
	}

	sort(pt1.begin(), pt1.end());

	sort(pt2.begin(), pt2.end());

	vector<int> pt12(N), pt21(N);
	for (int i = 0; i < N; ++i) {
		pair<ll, ll> p1 = pt1[i];
		for (int j = 0; j < N; ++j) {
			if (p1.first == pt2[j].second && p1.second == pt2[j].first) {
				pt12[i] = j;
				pt21[j] = i;
				break;
			}
		}
	}

	ll minimum = INT64_MAX;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ll sq = abs(pt1[i].first - pt1[j].first) * abs(pt1[i].second - pt1[j].second);
			if (sq == 0)
				continue;
			ll p1 = i;
			ll p2 = pt12[i];
			ll p1n = j;
			ll p2n = pt12[j];
			ll num = max(max(p1n, p1) - min(p1n, p1), max(p2, p2n) - min(p2, p2n)) + 1;
			cerr << sq << " " << num << endl;
			if (num >= K)
				minimum = min(minimum, sq);
		}
	}

	cout << minimum << endl;
}

int main()
{
	pA();

	return 0;
}