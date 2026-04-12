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

int H, W;
string S[10];
int main()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') cnt++;
		}
	}
	if (cnt == H + W - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}
