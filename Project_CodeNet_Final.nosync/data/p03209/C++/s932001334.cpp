#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

vector<ll> a,p;

ll f(ll n, ll x){
	if(n==0){
		if(x<=0) return 0;
		else return 1;
	}
	else if(x<=1+a[n-1]) return f(n-1, x-1);
	else return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
}
 
int main(int argc, char const *argv[])
{
	ll n,x;
	cin >> n >> x;
	a.resize(n);
	p.resize(n);
	a[0] = 1;
	p[0] = 1;
	for(ll i=1; i<n; i++){
		a[i] = 2 * a[i-1] + 3;
		p[i] = 2 * p[i-1] + 1;
	}
	cout << f(n,x) << endl;
	return 0;
}