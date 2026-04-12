#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int x,y,z;
int ans;
int main(){
	cin>>x>>y>>z>>n>>m;
	k=min(n,m);
	if(x+y<=z*2){
		cout<<x*n+y*m;
		return 0;
	}
	ans+=k*2*z;
	n-=k;
	m-=k;
	if(n){
		if(x<=z*2)ans+=x*n;else ans+=2*z*n;
	}
	else{
		if(y<=z*2)ans+=y*m;else ans+=2*z*m;
	}
	cout<<ans;
	return 0;
} 