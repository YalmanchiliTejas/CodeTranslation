#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

const ll lp = 1e9+7;
int t,n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	ll sum=0, x;
	ll ans=0;
	for (int i=0; i<n; i++){
		cin >> x;
		ans = (ans + sum*x) % lp;
		sum = (sum + x) % lp;
	}
	
	cout << ans << endl;
	return 0;
}
