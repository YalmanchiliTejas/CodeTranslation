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

bool v[110], s[110];
int main()
{
	int H, W;
	string S[110];
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];
	for (int i = 0; i < H; i++) {
		bool de = true;
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') de = false;
		}
		v[i] = de;
	}
	for (int j = 0; j < W; j++) {
		bool de = true;
		for (int i = 0; i < H; i++) {
			if (S[i][j] == '#') de = false;
		}
		s[j] = de;
	}
	for (int i = 0; i < H; i++) {
		if (!v[i]) {
			for (int j = 0; j < W; j++) {
				if (!s[j]) cout << S[i][j];
			}
			cout << endl;
		}
	}
}
