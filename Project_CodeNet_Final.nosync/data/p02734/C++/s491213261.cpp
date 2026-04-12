#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n, s;
vector<ll> a;
const ll M = 998244353;

/*
	dp[i][val] : L <= x1 < x2 ... xk かつ Ax1 + ... + Axk がvalになる整数列(L,x1,x2...xk)の個数
*/
ll dp[3002][3002]; 



int main(){
	cin >> n >> s;
	a.resize(n);
	
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
	
	ll result = 0;
	for ( int i = 0; i < n; i++ ){
		//a[i]を使うことで数列が完成するなら、カウントする
		if ( a[i] < s ){
			if ( i != 0 )
				result = (result + dp[i-1][s-a[i]] * (n-i))%M;
		}
		else if ( a[i] == s ){
			result = (result + (i+1)*(n-i))%M;
		}
		
		// dpを計算
		for ( int j = 0; j <= s; j++ ){
			if ( i == 0 ){
				dp[i][j] = ( a[i] == j )  ? 1 : 0;
			}
			else {
				if ( j > a[i] ){
					dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i]])%M;
				}
				else if ( j == a[i] ){
					dp[i][j] = (dp[i-1][j] + (i+1))%M;
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	
	
	cout << result << endl;
	
	return 0;
}

