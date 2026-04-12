#include <bits/stdc++.h>

using namespace std;

#define int long long
#define M 1000000007

signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	int ans=0;
	int sum=0;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum=(sum+a[i])%M;
	}
	for(int i=0;i<n;i++){
		sum=(sum-a[i]+M)%M;
		ans=(ans+(a[i]*sum)%M)%M;
	}
	cout << ans << endl;
} 