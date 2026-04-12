#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<list>
#include<cstdint>
#include<vector>
#include<map>
#include<deque>
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;
const ll MOD = 1e9 + 7;
using namespace std;

int main() {
	//六日目

	cin.tie(0); ios::sync_with_stdio(false);

	int n = 0, m = 0;

	cin >> n >> m;
	
	int a, b;
	bool connect[10][10] = { false };
	

	rep(i, m) {
		cin >> a >> b;
		//接続を保存(順番は問わない) 1 true
		connect[a - 1][b - 1] = true;
		connect[b - 1][a - 1] = true;	
	}
	vector<int> permu(n);
	rep(i, n) {
		permu[i] = i;
	}

	int ans = 0;

	do{
		int isconnect = true;

		if (permu[0] == 1) {
			break; // 一番左(スタート)が、0(実際の数値だと１)でなくなった時点で終了
		}

		rep(i, n - 1) {
			if (connect[permu[i]][permu[i + 1]] == false) {
				isconnect = false;
			}
		}

		if (isconnect == true) {
			ans++;
		}

	} while (next_permutation(permu.begin(), permu.end()));

	cout << ans << endl;

	return 0;
}