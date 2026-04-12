#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
ll max(ll a, ll b){ 
	if(a >= b) return a;
	else if(a < b) return b;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ll n;
	cin >> n;
	ll ans = n*800 - 200*(n/15);
	cout << ans << endl;
}