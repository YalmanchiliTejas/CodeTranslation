#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[233],p,t,ans,cg;

int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ans=0;cg=n+1;p=n-1;
	while (cg--){
		p++;if (p==n) p=0;
		if (a[p]>=n){
			t=a[p]/n;
			a[p]=a[p]-t*n;
			for (int i=0;i<n;i++){
				if (i!=p){
					a[i]+=t;
				}
			}
			ans+=t;
			cg=n+1;
		}
		//for (int i=0;i<n;i++)printf(" %lld",a[i]);printf("\n");
	}
	cout<<ans;
}
