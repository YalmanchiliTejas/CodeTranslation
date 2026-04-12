#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,k,n,m,ans;
ll sum[60],S[60];
void fun(ll x,ll y){
//	cout<<x<<' '<<y<<' '<<sum[x-1]<<' '<<S[x-1]<<' '<<ans<<endl;
	if(x==0){
		if(y!=0)++ans;
		return;
	}--y;
	if(y>=sum[x-1]){
		ans+=S[x-1];
		y-=sum[x-1];
		if(y==0)return;
		--y;
		ans++;
	}
	if(y==0)return;
	fun(x-1,y);
	/*
	cout<<x<<' '<<y<<' '<<sum[x-1]<<' '<<S[x-1]<<' '<<ans<<endl;
	if(x==0);
	if(y<=1)return;
	if(y<sum[x-1]+2)fun(x-1,y);
	else{
		ans+=S[x-1]+1;
		//cout<<x<<' '<<ans<<endl;
		fun(x-1,y-sum[x-1]-1);
	}*/
}
int main(){
	cin>>n>>m;
	sum[0]=S[0]=1;
	for(i=1;i<=50;i++){
		sum[i]=sum[i-1]*2+3;
		S[i]=S[i-1]*2+1;
//		cout<<m<<endl<<sum[i]<<' '<<S[i]<<endl;
	}
	fun(n,m);
	cout<<ans<<endl;
	return 0;
}