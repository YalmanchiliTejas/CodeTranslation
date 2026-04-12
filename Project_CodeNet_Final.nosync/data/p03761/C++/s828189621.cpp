#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int cnt[51][26];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			cnt[i][S[j] - 'a']++;
		}
	}
	string ans;
	for (int j = 0; j < 26; j++) {
		int c = mod;
		for (int i = 0; i < N; i++) {
			c = min(c, cnt[i][j]);
		}
		for (int i = 0; i < c; i++) {
			ans.push_back((char)('a' + j));
		}
	}
	cout << ans << endl;
}
