#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r,a[100000];
	while(cin>>n>>l>>r,n){
		int ans=0;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=l;i<=r;i++){
			int flag=0;
			for(int j=0;j<n;j++){
				if(i%a[j]==0){
					if(j%2==0)ans++;
					flag++;
					goto L;
				}
			}
			L:;
			if(!flag){
				if(n%2==0)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
