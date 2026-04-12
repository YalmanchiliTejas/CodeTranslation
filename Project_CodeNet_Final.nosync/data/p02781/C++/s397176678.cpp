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
// vector<vector<int>> data(3, vector<int>(4));

ll comb(ll l, ll k) {
	if (l < k) return 0;
	if (k == 0) return 1;
	if (k == 1) return l;
	if (k == 2) return l*(l-1)/2;
	if (k == 3) return l*(l-1)*(l-2)/6;
	return 0;
}

int main(){	
	string N;
	long long K;
	cin >> N;
	scanf("%lld",&K);
	ll nine[4];
	nine[0] = 1;
	nine[1] = 9;
	nine[2] = 81;
	nine[3] = 729;

	ll len = N.length();
	// if (len < K) cout << "0" << endl;
	ll res = 0;
	rep(i, len) {
		ll a = N[i]-'0';
		if (a > 0 && K > 0) {
			res += (a-1)*comb(len-1-i, K-1)*nine[K-1]+comb(len-1-i, K)*nine[K];
			K--;
		}
	}
	if (K == 0) res++;
	cout << res << endl;

	return 0;
}

