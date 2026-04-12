#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n,k; cin >> n >> k;
	ll ans = 0;
	for(int b=k+1; b<=n; b++){
		ans += n/b*max(0,b-k)+max(0,n%b-k+1);
//		cout << n/b*max(0,b-k)+max(0,n%b-k+1) << endl;
	}
	if(k>0)cout << ans << endl;
	else cout << ll(n)*n << endl;
}
