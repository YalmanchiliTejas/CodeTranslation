#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n)repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
typedef pair<int,int> P;
typedef pair<int, P> PP;
#define all(v) v.begin(),v.end()
#define fi first
#define se second
const int inf = 1e9;

signed main(){
	int n;
	scanf("%lld", &n);
	int ans = n*800-200*(n/15);
	printf("%lld\n", ans);
	return 0;
}