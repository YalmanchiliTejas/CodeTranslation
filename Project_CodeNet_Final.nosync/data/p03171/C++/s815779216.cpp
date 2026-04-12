#define _CRT_SECURE_NO_WARNINGS
/*                   وتزودوا فإن خير الزاد التقوى                    */
/*       وما تدري نفس ماذا تکسب غدا وما تدري نفس باي ارض تموت      */
#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define endl '\n'
#define ll long long
#define PI acos(-1)
#define watch(x) cerr<<#x<<" = { "<<x<<" }\n"
#define sz(n) n.size()
#define Mo7med_Sayed fast();
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v) return cout<<v,0;
const double EPS = (1e-7);
const ll OO = INT_MAX, mod = 1e9 + 7;
void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
ll n, m, k, t;
vector<ll>v;
ll dp[3005][3005][2];
ll solve(int x,int y,bool b) {
	if (x>y)return 0;
	ll& ret = dp[x][y][b];
	if (~ret)return ret;
	if (b) {
		ret = max(solve(x + 1, y, b ^ 1) + v[x], solve(x , y-1, b ^ 1) + v[y]);
	}
	else {
		ret= min(solve(x + 1, y, b ^ 1) , solve(x , y-1, b ^ 1));
	}
	return ret;
}

int main()
{
	//run();
	Mo7med_Sayed;
	cin >> n;
	v.resize(n);
	memset(dp, -1, sizeof dp);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i] ; sum += v[i];
	}
	cout << solve(0, n - 1, 1)*2-sum;

}

