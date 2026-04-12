using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <set> 
#include <unordered_set>
#include <string>
#include <functional>
#include <limits.h>
//#include <bits/stdc++.h> 
//#include <list>
#include <stack>
#include <stdio.h>
typedef signed long long ll; //watch out ll= int*int will not become ll, rather (ll)ini*int casting will work
#include <queue>
#include <math.h>
#include <deque>
#define ffor(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
//typedef long float lf;
#include <cmath>
#include <iomanip>
#include <numeric>
#include <stdio.h>
const long double PI = 3.141592653589793238L;
/*struct CustomCompare
{
	bool operator()(pii& p1, pii& p2)
	{
		if (p1.second - p1.first == p2.second - p2.first)
			return p1.first > p2.first;

		return p1.second - p1.first < p2.second - p2.first;
	}
};*/
int tt, n, k, inp, a, b, x,m;
void pv(vector<int> a) {
	for (auto i : a)
		cout << i<< ' ';
	cout << '\n';
}
void pp (vector<pair<int, int>> a) {
	for (auto i : a)
		cout << i.first << ' ' << i.second<<'\n';
}
double solve(tuple<int, int, int> s,
	map <tuple <int, int, int>, double> &memo) {
	//cout << get<0>(s) << ' '<< get<1>(s) << ' '<< get<2>(s);
	//cout << endl;
	if (memo.find(s) == memo.end()) {
		int i = get<0>(s);
		int j = get<1>(s);
		int k = get<2>(s);
		
		//cout << "FIRST";
		double ans = 0;
		if (k>0)
		ans +=(double) k / n * (1 + solve({ i,j + 1,k-1 }, memo));
		
		
		//cout << "SECOND";
		if (j>0)
		ans += (double)  j / n * (1 + solve({ i + 1,j-1,k }, memo));
		
		
		//cout << "THIRD";
		if (i>0)
		ans += (double)     i / n * (1 + solve({ i-1,j,k }, memo));
		
		//cout << "FOURTH";
		ans = (double) n / ((double)i + j + k) * (ans + (double)((double)n - i - j - k) / n);
		
		//cout << "ANS " << ans << '\n';
		memo.insert({ s, ans });
		return ans;
	}
	else
		return memo.find(s)->second;

}
int main() {
	//vector<int> x = { 2,1,0 };
	cin >> n; 
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//cout << minn;
	vector<vector<long long>> dp(n, vector<long long> (n));
	for (int i = 0; i < n; i++)
		dp[i][i] = (long long)a[i];
	for (int k = 1; k < n + 1; k++) {
		//cout << k<<'\n';
		for (int start = 0; start < n - k; start++) {
			int end = start + k;
			dp[start][end] = max(
				a[start] - dp[start + 1][end],
				a[end] - dp[start][end - 1]);
		}
	
	}
	//for (auto i : dp)
	//	pv(i);
		cout << dp[0][n - 1];
}


/*
tuple <int, int, int> s = {0,0,0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			get<0>(s)++;
		else if (a[i]==2)
			get<1>(s)++;
		else if (a[i] == 3)
			get<2>(s)++;

	}
	map <tuple <int, int, int>, double> memo;
	memo.insert({ {0,0,0},0.0 });
	cout << std::setprecision(11)<<solve(s, memo);
}*/