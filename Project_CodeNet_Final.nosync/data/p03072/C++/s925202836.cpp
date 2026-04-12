
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<functional>

using namespace std;
#define LL long long
#define ALF "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LLBIG 1999999999999999999
#define INTBIG 1111111111
#define MOD 1000000007
#define PI pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>>

int main() {
	int n; cin >> n;
	int h = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int H; cin >> H;
		if (h <= H) {
			ans++; h = H;
		}
	}
	cout << ans << endl;

	return 0;
}
