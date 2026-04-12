#include<bits/stdc++.h>
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define int long long
#define ve vector<int>
#define mod 1000000007
#define eb emplace_back
#define inf ((long long) 1e18 )
#define all(x) (x).begin(),(x).end()
#define debug(x) cout << '>' << #x << ':' << x << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug2(x,y) cout << '>' << #x <<" = "<< x <<" & "<< #y <<" = "<< y << '\n';
#define fileIO freopen("input.txt", "r", stdin); freopen("output2.txt", "w", stdout);
using namespace std;
const int N = 1e6 + 7;

int32_t main()
{
	IOS
#ifndef ONLINE_JUDGE
	fileIO
#endif
	int t;
	t = 1;
	while (t--) {
		int x;
      	cin >> x;
      	if(x >= 30)
          	cout << "Yes\n";
      	else
          	cout << "No\n";
	}
	return 0;
}
