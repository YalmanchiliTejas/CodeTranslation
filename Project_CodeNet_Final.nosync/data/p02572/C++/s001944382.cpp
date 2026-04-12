
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
// Parsed on: 2020-08-29 17:30:03
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio  ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
	using ll = unsigned long long;
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(auto&e : arr) cin >> e;
	vector<ll> suffix(n);
	suffix[n-1] = arr[n-1];
	for(int a = n-2; a >= 0; a--){
		suffix[a] = (suffix[a+1]%1000000007 + arr[a])%1000000007;
	}
	
	ll ans = 0;
	for(int a=0;a<n-1;a++)
	{
		ans = (ans%1000000007 + (arr[a]*suffix[a+1])%1000000007)%1000000007;
	}
	cout << ans;
	
	return 0;
}
