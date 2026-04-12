#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9+7;

ll C(ll a,ll b){
		if(b<0) return 0;
		if(b>a) return 0;
		if(b==0) return 1;
		if(b==1) return a;
		if(b==2) return a*(a-1)/2;
		return 0;
}		
	
ll power (ll a,ll b){
		if(b<0)
			return 0;
		return pow(a,b);	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int k;
	cin>>s>>k;
	
	ll l = s.length();
	ll ans = 0;
	for(ll i=k;i<=l-1;i++){
		ll p = power(9,k);
		ll cc = C(i-1,k-1);
		ans += (p*cc);
		//ctrl + /cout<<i<<" "<<p<<" "<<cc<<" "<<ans<<"\n";
	}
	ans += (s[0] - '0' - 1) * C(l-1,k-1) * power(9,k-1);
	if(k==1) { 
		ans++;
		cout<<ans;
		return 0;
	}
	int i=1;
	for(;i<l;i++){
		if(s[i] != '0')
			break;
	}
	if(i<l){
		ans += C(l-i-1,k-1) * power(9,k-1);
		ans += (s[i] -'0' -1) * C(l-i-1,k-2) * power(9,k-2);
		if(k==2) {
			ans++;
			cout<<ans;
			return 0;
		}
	}
	i++;
	if(i<l){
		for(;i<l;i++)
			if(s[i] != '0')
				break;
	}
	if(i<l){
		ans += C(l-i-1,k-2) * power(9,k-2);
		ans += (s[i] - '0' - 1) * C(l-i-1,k-3) * power(9,k-3);
		if(k==3) ans++;
	}
	cout<<ans;
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	























