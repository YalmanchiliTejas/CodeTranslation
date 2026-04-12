#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int64_t extgcd(int64_t a,int b,int64_t&x,int64_t&y){
	int64_t d=a;
	if(b){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1,y=0;
	}
	return d;
}

int64_t modinv(int64_t base){
	int64_t x,y;
	extgcd(base,mod,x,y);
	x%=mod;
	return (x<0?x+mod:x);
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int64_t>a(n); for(auto&&i:a)cin>>i;
	int64_t base=0;
	for(auto&&i:a)base=(base+i)%mod;
	int64_t ans=0;
	for(auto&&i:a)ans=(ans+1L*i*(mod+base-i)%mod)%mod;
	cout<<ans*modinv(2)%mod<<"\n"s;
}
