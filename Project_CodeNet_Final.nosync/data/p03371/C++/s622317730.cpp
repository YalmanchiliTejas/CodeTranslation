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
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll ans = 0;
	if(a+b>c*2){
		int ab = min(x, y);
		ans += ab * c * 2;
		x -= ab; y -= ab;
	}
	ll ans2 = ans;
	ans += x*a;
	ans += y*b;
	ans2 += max(x,y)* c*2;
	cout<<min(ans, ans2)<<endl;
	return 0;
}