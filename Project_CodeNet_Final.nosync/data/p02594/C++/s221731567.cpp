#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define prl pair<ll,ll>
#define pri pair<int,int>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define db double
#define N 100005
#define mod 1000000007
#define INF 2147483647
using namespace std;
mt19937 mrand(random_device{}());
uniform_int_distribution<ll> dist(0, 100000000);
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll qpow(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; }return res; }

int main() {
	IOS;
	int x;
	cin >> x;
	string a;
	a = x >= 30 ? "Yes" : "No";
	cout <<a;
	return 0;
}
