#include <bits/stdc++.h>
using namespace std;

int main (void){
	int n, l, r;
	while(cin>>n>>l>>r, n+l+r){
		int ans = 0;
		vector<int> a(n+1);
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		for(int y = l; y <= r; ++y){
			int i = 1;
			while(i <= n && y % a[i] != 0) i++;
			if(i==n+1){
				if(n%2==0){
					ans++;
				}
			}else{
				if(i%2==1){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
