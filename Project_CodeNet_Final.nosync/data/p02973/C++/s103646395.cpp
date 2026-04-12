#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

vector<long long> divisor(long long n) {
	vector<long long> res;
	for (long long i = 1; i * i <= n; i++) {
  	if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}
	return res;
}

int main(){	
	long long N;
	cin >> N;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	vector<ll> b(N, -1);
	rep(i, N) {
		b[POSL(b,a[i])-1] = a[i];
		// cout << POSL(b,a[i]) << " " << b[POSL(b,a[i])] << endl;
	}
	ll res = 0;
	for (ll i = N-1; i >= 0; i--) {
		if (b[i] != -1) res++;
	}
	cout << res << endl;
	return 0;
}

