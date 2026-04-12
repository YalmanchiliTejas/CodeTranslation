#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
signed main(){
	int n,h[20];
	cin>>n;
	rep(i,n)cin>>h[i];
	int pan=0;
	int ans=0;
	rep(i,n){
		if(h[i]>=pan){
			ans++;
			pan=h[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
