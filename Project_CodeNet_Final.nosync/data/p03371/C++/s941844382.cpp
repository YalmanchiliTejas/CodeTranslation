#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll ans = INF; 
	for(int i = 0; i<=max(x,y); ++i){
		ll cost = c*2*i+a*max(0,(x-i))+b*max(0,(y-i));
		ans = min(ans, cost);
	}
	cout<<ans<<endl; return 0;
}
