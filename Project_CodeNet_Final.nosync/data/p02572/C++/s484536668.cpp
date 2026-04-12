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
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> sum(N+1, 0);
	rep(i,N){
		cin >> A[i];
		sum[i+1] = sum[i] + A[i];
		sum[i+1] %= MOD;
	}
	ll ans = 0;
	rep(i,N){
		ans += A[i] * ((sum[N]-sum[i + 1])%MOD);
		ans %= MOD;
	}
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}
