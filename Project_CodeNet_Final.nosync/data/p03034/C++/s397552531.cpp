#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	int ans = 0;
	for(int i=1;i<=n-1;i++){
		int res = 0;
		int lim = (n-1)/i;
		if( (n-1)%i == 0 ) lim =  ( (n-1)/i - 1 ) / 2;
		for(int j=1;j<=lim;j++){
			if( n-1-j*i <= i )break;
			res += a[j*i];
			res += a[n-1-j*i];
			if(res > ans)ans = res;
		}
	}
	cout<<ans<<endl;
	return 0;
}