#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include<limits.h>
#include<float.h>
#include<list>
#include <array>
#include <complex>
#include<stdio.h>
#include<string.h>
#include <bitset>
#include<random>
using namespace std;

int findI(vector<int>& A, int x)
{
	int ans = INT_MAX;
	for (int i = 1; i <= A.size(); ++i) if (x % A[i - 1] == 0) ans = min(i, ans);
	if (ans == INT_MAX) ans = -1;
	return ans;
}
int main()
{
	vector<int> AN;
	while (1)
	{
		int n, l, r;
		cin >> n >> l >> r;
		if (n == 0) break;
		vector<int> A(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) cin >> A[i];
		for (int x = l; x <= r; ++x)
		{
			int i = findI(A, x);
			if (i != -1 && (i % 2 == 1)) ++ans;
			if (i == -1 && (n % 2 == 0)) ++ans;
		}
		AN.push_back(ans);
	}
	for (const auto& a : AN)
		cout << a << endl;
	return 0;
}
