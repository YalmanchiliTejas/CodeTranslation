#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char c;
	map<char, int>mp;
	for (int i = 2; i < 10; i++) {
		mp[i + '0'] = i;
	}
	mp['T'] = 10;
	mp['J'] = 11;
	mp['Q'] = 12;
	mp['K'] = 13;
	mp['A'] = 14;
	while (cin >> c, c != '#') {
		vector<vector<string>>s(4, vector<string>(13));
		int cn = 0;
		for (auto &i : s)for (auto &j : i)cin >> j;
		int a = 0, b = 0;
		for (int i = 0; i < 13; i++) {
			int win = cn;
			for (int j = 0; j < 4; j++) {
				if (s[j][i][1] == c) {
					if (s[win][i][1] == c) {
						if (mp[s[j][i][0]] > mp[s[win][i][0]])win = j;
					}
					else win = j;
				}
				else if(s[j][i][1]==s[cn][i][1]){
					if (s[win][i][1] != c) {
						if (mp[s[j][i][0]] > mp[s[win][i][0]])win = j;
					}
				}
			}
			if (win & 1)b++;
			else a++;
			cn = win;
		}
		if (a > b)cout << "NS " << a - 6 << endl;
		else cout << "EW " << b - 6 << endl;
	}
}
