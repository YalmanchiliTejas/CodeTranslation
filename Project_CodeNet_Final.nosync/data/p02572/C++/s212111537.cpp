#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int extgcd(int a,int b,int&x,int&y){
	int d=a;
	if(b){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1,y=0;
	}
	return d;
}

int modinv(int base){
	int x,y;
	extgcd(base,mod,x,y);
	x%=mod;
	return (x<0?x+mod:x);
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int>a(n); for(auto&&i:a)cin>>i;
	int base=0;
	for(auto&&i:a)base=(base+i)%mod;
	int ans=0;
	for(auto&&i:a)ans=(ans+1L*i*(mod+base-i)%mod)%mod;
	cout<<1L*ans*modinv(2)%mod<<"\n"s;
}
