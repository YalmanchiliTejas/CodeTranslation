#include <bits/stdc++.h>
using namespace std;
#define rep(a, n) for (int i = a; i < n; i++)
#define per(a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main() {
	int n;
	cin>>n;
	vector<long long>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	long long suff_sum = 0;
	long long ans = 0;
	for(int i=n-1;i>=0;i--){
		ans = (ans + (v[i]*suff_sum)%mod)%mod;
		suff_sum = (suff_sum + v[i])%mod;
	}
	cout<<ans;
}