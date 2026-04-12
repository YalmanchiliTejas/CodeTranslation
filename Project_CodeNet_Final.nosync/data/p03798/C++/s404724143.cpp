#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<stdio.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)

const ll INF = 1LL << 60;

typedef pair<ll, double> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
	return firstElof.second < secondElof.second;
}

bool IsPrime(ll num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

signed main() {
	ll n;
	cin >> n;
	vector<char>a(n);
	vector<char>ans(n);
	rep(i, n) {
		cin >> a[i];
	}
	char judge;
	char judgeFirst;
	bool judged = false;
	//1
	ans[0] = 'S';
	ans[1] = 'S';
	if (a[0] == 'o')judge = 'S';
	else judge = 'W';
	for (ll i = 2; i < n; i++) {
		if ((a[i - 1] == 'o' && ans[i - 1] == 'S') || (a[i - 1] == 'x' && ans[i - 1] == 'W')) {
			ans[i] = ans[i - 2];
		}
		else {
			if(ans[i-2]=='S')ans[i] = 'W';
			else ans[i] = 'S';
		}
	}
	if ((a[n - 1] == 'o' && ans[n - 1] == 'S') || (a[n - 1] == 'x' && ans[n - 1] == 'W')) {
		judgeFirst = ans[n - 2];
	}
	else {
		if (ans[n - 2] == 'S')judgeFirst = 'W';
		else judgeFirst = 'S';
	}
	if (judge == ans[n - 1] && judgeFirst == ans[0])judged = true;

	if (judged == false) {
		//2
		ans[0] = 'S';
		ans[1] = 'W';
		if (a[0] == 'o')judge = 'W';
		else judge = 'S';
		for (ll i = 2; i < n; i++) {
			if ((a[i - 1] == 'o' && ans[i - 1] == 'S') || (a[i - 1] == 'x' && ans[i - 1] == 'W')) {
				ans[i] = ans[i - 2];
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		if ((a[n - 1] == 'o' && ans[n - 1] == 'S') || (a[n - 1] == 'x' && ans[n - 1] == 'W')) {
			judgeFirst = ans[n - 2];
		}
		else {
			if (ans[n - 2] == 'S')judgeFirst = 'W';
			else judgeFirst = 'S';
		}
		if (judge == ans[n - 1] && judgeFirst == ans[0])judged = true;
	}

	if (judged == false) {
		//3
		ans[0] = 'W';
		ans[1] = 'S';
		if (a[0] == 'o')judge = 'W';
		else judge = 'S';
		for (ll i = 2; i < n; i++) {
			if ((a[i - 1] == 'o' && ans[i - 1] == 'S') || (a[i - 1] == 'x' && ans[i - 1] == 'W')) {
				ans[i] = ans[i - 2];
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		if ((a[n - 1] == 'o' && ans[n - 1] == 'S') || (a[n - 1] == 'x' && ans[n - 1] == 'W')) {
			judgeFirst = ans[n - 2];
		}
		else {
			if (ans[n - 2] == 'S')judgeFirst = 'W';
			else judgeFirst = 'S';
		}
		if (judge == ans[n - 1] && judgeFirst == ans[0])judged = true;
	}

	if (judged == false) {
		//4
		ans[0] = 'W';
		ans[1] = 'W';
		if (a[0] == 'o')judge = 'S';
		else judge = 'W';
		for (ll i = 2; i < n; i++) {
			if ((a[i - 1] == 'o' && ans[i - 1] == 'S') || (a[i - 1] == 'x' && ans[i - 1] == 'W')) {
				ans[i] = ans[i - 2];
			}
			else {
				if (ans[i - 2] == 'S')ans[i] = 'W';
				else ans[i] = 'S';
			}
		}
		if ((a[n - 1] == 'o' && ans[n - 1] == 'S') || (a[n - 1] == 'x' && ans[n - 1] == 'W')) {
			judgeFirst = ans[n - 2];
		}
		else {
			if (ans[n - 2] == 'S')judgeFirst = 'W';
			else judgeFirst = 'S';
		}
		if (judge == ans[n - 1] && judgeFirst == ans[0])judged = true;
	}
	if (judged == true) {
		rep(i, n) {
			cout << ans[i];
		}
	}
	else cout << -1;
}
