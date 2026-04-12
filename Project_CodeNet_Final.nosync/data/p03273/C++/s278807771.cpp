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
const int MOD = 998244353;

string S[110];
bool v[110], s[110];
int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];
	for (int i = 0; i < H; i++) {
		bool ok = true;
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') ok = false;
		}
		v[i] = ok;
	}
	for (int j = 0; j < W; j++) {
		bool ok = true;
		for (int i = 0; i < H; i++) {
			if (S[i][j] == '#') ok = false;
		}
		s[j] = ok;
	}
	for (int i = 0; i < H; i++) {
		if (!v[i]) {
			for (int j = 0; j < W; j++) {
				if (!s[j] && !v[i])cout << S[i][j];
			}
			cout << endl;
		}
	}
}
