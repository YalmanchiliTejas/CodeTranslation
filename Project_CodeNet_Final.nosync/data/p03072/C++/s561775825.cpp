//author : Brijesh1in
#include <bits/stdc++.h>

using namespace std;
	
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl '\n'
#define boost ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long li;
const int N = 1e5 + 10;


void solve(){

	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; ++i)
		cin>>a[i];
	int ans = 0;
	int prev = a[0];
	for(int i = 0 ; i < n ; ++i)
		if(a[i]>=prev)
			ans++ , prev = a[i];
	cout<<ans<<endl;
}
signed main(){

	int t;
	t = 1;
	//cin>>t;

	while(t--)
		solve();

}