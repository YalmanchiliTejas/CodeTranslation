#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55],p[55];
ll ans(ll i,ll nowx){
	if(nowx<=1){
		if(i==0)return 1;
		else return 0;
	}
	if(nowx<=a[i-1]+1)return ans(i-1,nowx-1);
	if(nowx==a[i-1]+2)return p[i-1]+1;
	if(nowx<=2*a[i-1]+2)return p[i-1]+1+ans(i-1,nowx-a[i-1]-2);
	return p[i];
}
int main(){
	ll n,x;
	cin>>n>>x;
	a[0]=p[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=2*a[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	cout<<ans(n,x);
	return 0;
}
