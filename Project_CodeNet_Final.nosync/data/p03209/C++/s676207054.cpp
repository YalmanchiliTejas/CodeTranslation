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
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	ll N,X;
	cin>>N>>X;
	vector<lp> table (N+1);
	table[0].first = 1;
	table[0].second = 1;
	REP(i,N){
		table[i].first = table[i-1].first*2 + 3LL;
		table[i].second = table[i-1].second*2 + 1LL;
	}
	ll ans = -1LL;
	++X;
	while(X>0){
		++ans;
		--X;
		for(int i = N; i>=0; --i){
			if(table[i].first <= X){
				ans += table[i].second;
				X -= table[i].first;
				N = i;
				break;
			}
			--X;
		}
	}
	cout<<ans<<endl;
	return 0;
}