#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
#define FastIO ios::sync_with_stdio(0)
#define Mod 1000000007
typedef long long ll;
int n;
ll memo[3003][3003],a[3003];
ll dp(int left, int right) {
	if (left > right)
		return 0;

	ll &ret = memo[left][right];
	if (ret != -1)return ret;
	
	if (n%2 == (right-left+1)%2)//taro
		ret = max(a[left] +	 dp(left + 1, right), a[right]+ dp(left, right - 1));
	else //jaro
		ret = min(dp(left + 1, right)-a[left],  dp(left, right - 1)-a[right]);
		
	return ret;

}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	//write; read;
#endif 
	memset(memo,-1,sizeof memo);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << dp(0, n - 1) << endl;
	
	return 0;
}