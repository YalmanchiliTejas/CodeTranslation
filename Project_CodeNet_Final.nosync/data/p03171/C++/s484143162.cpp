#include <cstdio>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
// #include <map>
#include <iomanip>
#include <cstring>
#include <cmath>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int uii;
typedef pair<int,int> pii;
typedef unsigned long long uLL; 
typedef vector<int> vii; 

const int maxn = 3333;
LL d[maxn][maxn], vis[maxn][maxn], a[maxn];

LL dp(int L, int R, int h){
	if(vis[L][R]) return d[L][R];
	vis[L][R] = 1;
	if(L == R){
		return d[L][R] = h * a[L];
	}
	if(h == 1){ 
		d[L][R] = max(dp(L + 1, R, -h) + h * a[L], dp(L, R - 1, -h) + h * a[R]);
	} else {
		d[L][R] = min(dp(L + 1, R, -h) + h * a[L], dp(L, R - 1, -h) + h * a[R]);
	}
	return d[L][R];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	dp(1, n, 1);
	cout << d[1][n] << endl;
	return 0;
}