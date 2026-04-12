#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
ll n,store[200050];
ll ans=0,cons=1000000007,sum=0;
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>store[i];
		store[i]=store[i]%cons;sum+=(store[i]);
	}
	for(int i=0;i<n;i++){
		sum-=store[i];ll summ=(sum%cons);
		ll nw=(((summ)*store[i])%cons);
		ans=((ans+nw)%cons);
	}
	cout<<ans<<endl;
	return 0;
}