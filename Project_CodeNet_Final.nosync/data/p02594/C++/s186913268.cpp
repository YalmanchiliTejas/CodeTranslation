#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define INF 2e9
using namespace std;
const int N=1e6+1;
const int mod=1e9+7;
ll fastexp(ll base,ll exp){
	base%=mod;
	ll ans=1;
	while(exp>0){
		if(exp&1){
			ans*=base;
			ans%=mod;
		}
		base*=base;
		base%=mod;
		exp/=2;
	}
	return ans;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int sumofdigits(int n){
	int sum = 0;
	while(n!=0){
		sum += n%10;
		n = n/10;
	}
	return sum;
}
int arr[N];
int ar[N];
int main() {
		int t;
		cin >> t;
		if(t >= 30){
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return 0;
}