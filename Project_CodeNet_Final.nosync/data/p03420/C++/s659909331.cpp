#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll ans = 0;
	rep(b,1,n+1){
		ll ans1 = 0;
		if(b<=k)continue;
		ll c = (n+1)/b;
		ll d = (n+1)%b;
		ans1 += (b-k)*c;
		ans1 += max(d-k,0LL);
		if(k==0)ans1--;
		ans += ans1;
	}
	cout << ans << endl;
	return 0;
}