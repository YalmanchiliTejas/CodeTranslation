#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// 間に2個空きがある → skip++;
// 間に3個空きがある → skip += 2;
// Nが偶数なら skip=1 まで許可、奇数ならskip=2まで許可

struct dpdata{
	ll x01;   // a[i] を選んだ
	ll x11;   // a[i] を選んだ skip1
	ll x21;   // a[i] を選んだ skip2

	ll x00;   // a[i] を選んでない
	ll x10;   // a[i] を選んでない skip1
	ll x20;   // a[i] を選んでない skip2
};

dpdata dp[200005];

int main(){
	ll n;
	cin >> n;
	
	vector<ll> a(n);
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
	
	
	dp[0] = { a[0], 0, 0, 0, 0, 0 };
	
	for ( int i = 1; i < n; i++ ){
		dpdata &d = dp[i-1];
		
		dp[i] = {
			     d.x00 + a[i],
			     d.x10 + a[i],
			     d.x20 + a[i],
			     
			     d.x01, 
			max( d.x11, d.x00 ),
			max( d.x21, d.x10 )
		};
	}
	
	{
		dpdata &d = dp[n-1];
		if ( n % 2 == 0 ){
			cout << max({d.x00, d.x01, d.x11}) << endl;
		}
		else {
			cout << max({d.x00, d.x10, d.x21, d.x11}) << endl;
		}
	}
	
	return 0;
}


