#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp mak_pair
#define pb push_back
int n;
ll x[200000];
ll mod=int(1e9+7);
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll s=0,res=0;
	for(int i=0;i<n;i++)cin>>x[i],s+=x[i];
	s%=mod;
	for(int i=0;i<n;i++){
		s-=x[i];
		s=(s+mod)%mod;
		res+=(x[i]*s+mod)%mod;
		res=(res+mod)%mod;
	}
	cout<<(res+mod)%mod;
	return 0;
}