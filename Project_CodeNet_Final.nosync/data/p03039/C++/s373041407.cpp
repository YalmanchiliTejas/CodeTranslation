#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<pi> vpi;

#define debugone(x) cerr << #x << " " << x << endl;
#define debugtwo(x) cerr << #x << "-------------" << endl;for(auto &it: x) cerr << it << " ";cerr << endl;
#define debugthree(x, i, j) cerr << #x << "------------" << endl;cerr << "from " << i << " to " << j << endl;for(int k=i; k<=j; k++) cerr << x[k] << " ";cout << endl;

const int mod = (int)1e9 + 7;

ll power_mod(ll x, ll n){
	if(n == 0) return 1LL;
	else if(n % 2 == 0){
		ll temp = power_mod(x, n/2);
		return (temp * temp)%mod;
	}
	else return (power_mod(x, n-1) * x)%mod;
}
long long inverse(long long n){
	return power_mod(n, mod - 2);
}
long long multiply(long long n, long long m){
	return (n * m)%mod;
}

long long divide(long long n, long long m){
	return (n * inverse(m))%mod;
}


int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	const int N = (int)2e5 + 10;
	long long factorial[N];
	factorial[0] = 1;

	for(int i = 1; i < N; i++){
		factorial[i] = ((long long)(i) * factorial[i - 1]) % mod;
	}

	long long ans = 1;

	ans = multiply(ans, factorial[n * m - 2]);
	ans = divide(ans, factorial[k - 2]);
	ans = divide(ans, factorial[n * m - k]);


	ll tempSum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ll one = ((((ll)(m - j + 1)) * ((ll)(m - j)) * n)/2) % mod;
			ll two = ((((ll)(n - i + 1)) * ((ll)(n - i)) * m)/2) % mod;
			ll three = (one + two) % mod;
			tempSum += three;
			tempSum %= mod;
		}
	}

	ans = multiply(ans, tempSum);
	cout << divide(ans, 1) << endl;
}	