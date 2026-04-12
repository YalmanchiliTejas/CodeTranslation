#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long a[100010];
int main() {
#define int long long
	int n;
	deque<int> que;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int co = 0;
	que.push_back(a[0]);
	co++;
	int co1 = 2, co2 = 2;
	while (co < n) {
		que.push_front(a[n - co1]);
		co++;
		if (co == n) {
			break;
		}
		que.push_back(a[n - co1 + 1]);
		co++;
		if (co == n) {
			break;
		}
		co1 += 2;
		que.push_front(a[0 + co2 - 1]);
		co++;
		if (co == n) {
			break;
		}
		que.push_back(a[0 + co2]);
		co++;
		if (co == n) {
			break;
		}
		co2 += 2;
	}
	deque<int> que1;
	que1.push_back(a[n - 1]);
	co = 0, co1 = 2, co2 = 2;
	co++;
	while (co < n) {
		que1.push_front(a[0 + co2 - 2]); 
		co++;
		if (co == n) {
			break;
		}
		que1.push_back(a[0 + co2 - 1]);
		co++;
		if (co == n) {
			break;
		}
		co2 += 2;
		que1.push_front(a[n - co1]);
		co++;
		if (co == n) {
			break;
		}
		que1.push_back(a[n - co1 - 1]);
		co++;
		if (co == n) {
			break;
		}
		co1 += 2;
	}
	long long ans = que.back(), ans2 = que1.back();
	que.pop_back();
	que1.pop_back();
	long long ans1 = 0, ans3 = 0;
	while (!que.empty()) {
		ans1 += abs(ans - que.back());
		ans3 += abs(ans2 - que1.back());
		ans = que.back();
		ans2 = que1.back();
		que.pop_back();
		que1.pop_back();
	}
	cout << max(ans1,ans3) << endl;
	return 0;
}