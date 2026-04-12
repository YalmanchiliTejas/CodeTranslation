//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repp(i, m, n) for(int i = m; i < (int)n; i++)
#define reps(i, n) for(int i = 1; i <= (int)n; i++)
#define pb push_back
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;

int main()
{
	int n;
	int a[200010], b[200010];
	cin >> n;
	rep(i, n)
	{
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a, a+n);
	int x=a[(n/2)-1], y=a[n/2];
	rep(i, n)
	{
		if(b[i]<=x) cout << y << endl;
		else cout << x << endl;
	}
	return 0;
}