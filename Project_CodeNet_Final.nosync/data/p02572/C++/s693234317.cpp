#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll mod=1e9+7;

ll n;
cin>>n;
vector<ll> a(n);
ll s=0;
for(int i=0;i<n;i++){
cin>>a[i];
s+=a[i];
}
ll c=0;
for(int i=0;i<n-1;i++){
s-=a[i];
	c+=((s%mod)*(a[i]%mod))%mod;
	c=c%mod;
	
}	
	
cout<<c;

 
}