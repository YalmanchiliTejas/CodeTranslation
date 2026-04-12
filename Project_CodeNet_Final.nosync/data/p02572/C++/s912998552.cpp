#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9+7;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<ll> v(n);
	for(auto &x: v)cin >> x;
	vector<ll> suf(n);
	suf[n-1] = v[n-1];
	for(int i = n-2;i >= 0;i--)
		suf[i] = (v[i] + suf[i+1])%P;
	int ans = 0;
	for(int i = 0;i < n-1;i++)
	{
		ans = (ans + (v[i] * suf[i+1])%P)%P;
	}
	cout << ans;
}
