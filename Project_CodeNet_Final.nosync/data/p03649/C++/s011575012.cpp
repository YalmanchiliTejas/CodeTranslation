#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=52;
const ll mod=1e9+7;
const ll inf=1e9+500;


ll a[maxn];
int main(){
ll n;
cin>>n;
for(ll i=0;i<n;i++){
	cin>>a[i];
}
ll ans=0;
while(1){
	ll res=0;
	for(ll i=0;i<n;i++){
		res+=a[i]/n;
	}	
	if(res==0){
		break;
	}
	ans+=res;
	for(ll i=0;i<n;i++){
		a[i]=(a[i]%n)+(res-a[i]/n);
	}
}
cout<<ans;


}

