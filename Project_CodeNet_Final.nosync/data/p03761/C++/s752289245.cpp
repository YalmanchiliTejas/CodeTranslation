#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
ll dp[2][4];
int now = 0;
int t[3];
ll p2[32];
bool use[100010];
int arr[256];
void Sequence() {

	int n;
	cin >> n;
	string t[51];
	for (size_t i = 0; i < n; i++)
	{
		cin >> t[i];
		sort(t[i].begin(),t[i].end());
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		arr[i] = 100;
	}
	for (size_t i = 0; i < n; i++)
	{
		int ta[256];
		fill(ta, ta + 256, 0);
		for (size_t j = 0; j < t[i].size(); j++)
		{
			ta[t[i][j]]++;
		}

		for (int j = 'a'; j <= 'z'; j++)
		{
			arr[j] = min(arr[j], ta[j]);
		}
	}
	string res = "";
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (size_t j = 0; j < arr[i]; j++)
		{
			res += i;
		}
	}
	cout << res << endl;
}
int main() {
	Sequence();
	return 0;
}

