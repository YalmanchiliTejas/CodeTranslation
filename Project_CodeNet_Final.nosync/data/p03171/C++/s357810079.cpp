#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;
 
#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
 
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[3010][3010];
int N;
vector<int> a;
bool flag[3010][3010];

ll solve(int L,int R){
	if(flag[L][R]) return dp[L][R];
	flag[L][R] = 1;
	if(L == R) return dp[L][R] = a[L];
	ll res = max(a[L]-solve(L+1,R),a[R]-solve(L,R-1));
	return dp[L][R] = res;
}
 
int main(){
	cin >> N;
	a.resize(N);
	rep(i,N) cin >> a[i];
	ll ans = solve(0,N-1);
	cout << ans << endl;
}
