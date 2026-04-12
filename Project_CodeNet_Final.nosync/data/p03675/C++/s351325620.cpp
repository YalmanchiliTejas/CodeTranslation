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

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

int main() {
	ll n;
	cin>>n;
	deque<ll> dq;
	ll b;
	cin>>b;
	dq.push_back(b);
	rep(i,0,n-1){
		ll a;
		cin>>a;
		if(i%2==0){
			dq.push_back(a);
		}
		else{
			dq.push_front(a);
		}
	}
	vector<ll> v(all(dq));
	if(n%2==0){
		reverse(all(v));
	}
	rep(i,0,n){
		cout << v[i];
		if(i!=n-1)cout << " ";
	}
	cout << endl;
    return 0;
}