#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll m=1e9+7;
int main(){
int n;
cin>>n;
ll a[n];
ll pref[n];
memset(pref,0,sizeof(pref));
for(ll &z:a){ cin>>z; }
pref[0]=a[0];
for(int i=1;i<n;i++){
	pref[i]=pref[i-1]+a[i];
}
ll s=0;
for(int i=0;i<n-1;i++){
	//(s+=((pref[n-1]-pref[i])*a[i]))%=m;
  	ll f=(pref[n-1]-pref[i])%m;
  	s+=(f*a[i]);
  	s%=m;
}
cout<<s;
return 0;
}
