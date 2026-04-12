#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (int i=0;i<N;i++)

//変数群
int N, M;
vector<int> vec;
int ans = 0;
vector<pair<int,int>> ab;

bool joint(int a,int b) {
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	rep(i, M) {
		if (ab[i].first == a && ab[i].second == b) {
			return true;
		}
	}
	return false;
}

int judge() {

	bool flag = true;
	rep(i, N - 1) {
		if (!joint(vec[i], vec[i + 1])) flag = false;
	}

	if (flag) {
		//cout << "true" << endl;
		return 1;
	}
	else {
		//cout << "false" << endl;
		return 0;
	}
}

//解法
void solve(int num) {

	//値を繰り返し、前に出ていた値なら次へ
	rep(i, N) {

		bool flag = true;
		rep(j, num) {
			if (vec[j] == i) flag = false;;
		}
		if (!flag) continue;

		vec[num] = i;

		if (num == N - 1) {
			rep(i, N) {
				//cout << vec[i] << "->";
			}
			ans+=judge();
		}
		else {
			solve(num + 1);
		}

	}

}

int main() {
	//入力
	cin >> N >> M;
	vec.resize(N);
	ab.resize(M);
	rep(i, M) {
		cin >> ab[i].first >> ab[i].second;
		ab[i].first--;
		ab[i].second--;
	}
	vec[0] = 0;
	solve(1);
	cout << ans << endl;
	return 0;
}