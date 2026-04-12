#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define spn setprecision
using namespace std;
ll multiply(ll num1, ll num2, ll mod) { // with mod > 1e9
	ll ans = 0;
	num1 %= mod;
	num2 %= mod;
	while (num2) {
		if (num2&1) {
			ans += num1;
			ans %= mod;
		}
		num1 *= 2;
		num1 %= mod;
		num2 /= 2;
	}
	return ans;
}
ll powmod2(ll base,ll exponent,ll mod){ // with mod > 1e9
	ll ans = 1;
	while (exponent) {
		if (exponent&1) {
			ans = multiply(ans, base, mod);
		}
		base = multiply(base, base, mod);
		exponent /= 2;
	}
	return ans;
}
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int cp(string &a,string &b){
	int len=0;
	for(int i = 0;  i < min(a.length(),b.length()); i++){
		if(a[i]==b[i]){
			len++;
		}
		else{
			break;
		}
	}
	return len;
}
ll nc2(int &n){
	ll ans=n;
	ans*=n-1;
	ans/=2;
	return ans;
}
const int upperlimit = 1e6;
const int mod = 1e9+7;
int arr[101];
int main() {
	int a,b,ab,x,y,ans=0,temp;
	sd(a);
	sd(b);
	sd(ab);
	sd(x);
	sd(y);
	if(2*ab<a+b){
		temp=min(x,y);
		x-=temp;
		y-=temp;
		ans+=2*temp*ab;
		if(2*ab<a){
			ans+=2*x*ab;
			x=0;
		}
		if(2*ab<b){
			ans+=y*2*ab;
			y=0;
		}
	}
	ans+=x*a;
	ans+=y*b;
	pd(ans);
	return 0;
}