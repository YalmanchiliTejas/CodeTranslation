//https://atcoder.jp/contests/abc134/tasks/abc134_f
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int n,a[N],res = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;++i)
	{
		int p;
		cin >> p;
		int vt = upper_bound(a + 1,a + res + 1,p,greater<int>()) - a;
		res = max(res,vt);
		a[vt] = p;
	}
	cout << res; 
}