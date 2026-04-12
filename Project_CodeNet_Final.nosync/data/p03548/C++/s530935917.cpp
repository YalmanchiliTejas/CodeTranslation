#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define pb push_back
#define pf push_front

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;

ll gcd(ll x, ll y) {
	ll r;
	while ((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}
ll lcm(ll x, ll y) {
	x /= gcd(x, y);
	y /= gcd(x, y);
	return (x*y);
}

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	cout << ((x - z) / (y + z));
	return 0;
}