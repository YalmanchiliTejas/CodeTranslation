#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define Ma7moud_7amdy                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(arr, x) memset(arr, x, sizeof arr)
#define endl "\n"
#define watch(x) cout << #x << " = " << x << endl;
#define RT(x) return cout << (x), 0;
#define Accepted 0
typedef long long ll;
typedef vector<int> vi;
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
void Open()
{
#ifndef ONLINE_JUDGE 
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 3000 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
ll arr[N], n, mem[N][N][2];
ll solve(int i, int j, bool state) {
	if (i > j)return 0;
	ll& ret = mem[i][j][state];
	if (~ret)return ret;
	if (state) {
		ret = solve(i + 1, j, !state) + arr[i];;
		ret = max(ret, solve(i, j - 1, !state) + arr[j]);
	}
	else {
		ret = solve(i + 1, j, !state) + -arr[i];;
		ret = min(ret, solve(i, j - 1, !state) + -arr[j]);
	}

	return ret;
}
int main()
{
	Ma7moud_7amdy;
	Open_Sesame;
	clr(mem, -1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solve(0, n - 1, 1);
}
