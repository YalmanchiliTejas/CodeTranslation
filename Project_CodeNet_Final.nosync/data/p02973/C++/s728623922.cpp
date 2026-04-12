#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005],d[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	int ans=1;d[1]=a[n];
	for(int i=n-1;i>=1;i--){
		int k=upper_bound(d+1,d+1+ans,a[i])-d;
		if(k>ans) d[++ans]=a[i];
		if(d[k]>a[i]) d[k]=a[i];
	}
	cout<<ans<<endl;
}
