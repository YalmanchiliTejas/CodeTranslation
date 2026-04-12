#include<bits/stdc++.h>
using namespace std;
#define INF (1LL<<30)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long

signed main(){
	while(1){
		int n,l,r;
		cin>>n>>l>>r;
		if(n==0&&l==0&&r==0)break;
		int a[50];
		lp(i,n){
			cin>>a[i];
		}
		int ans=0;
		for(int i=l;i<=r;i++){
			int now=i;
			lp(j,n){
				if(now%a[j]==0){
					if(j%2==0)ans++;
					break;
				}
				if(j==n-1){
					if(n%2==0)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
