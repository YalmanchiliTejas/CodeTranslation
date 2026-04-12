#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353

vector<ll> a(110000,0);
vector<ll> maxlist(110000,-1);

bool isOK(ll index, ll key) {
    if (maxlist.at(index) < key) return true;
    else return false;
}

ll binse(ll key, ll sizem){
	ll left = -1;
	ll right = sizem;
	while (right-left>1){
		ll mid = left+(right-left)/2;
		if (isOK(mid, key)) right = mid;
		else left = mid;
	}
	return right;
}


int main(){
	ll n; cin >> n;
	REP(i,n) cin >> a[i];
	maxlist.at(0) = a.at(0);
	ll size0 = 1;
	FOR(i,1,n-1){
		if (binse(a.at(i),size0) == size0){
			maxlist.at(size0) = a.at(i);
			size0++;
		}
		else {
			maxlist.at(binse(a.at(i),size0)) = a.at(i);
		}
	}
	cout << size0 << endl;
}