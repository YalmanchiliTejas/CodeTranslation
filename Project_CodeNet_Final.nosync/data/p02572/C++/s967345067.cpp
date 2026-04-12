#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
const ll mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const ll INF = (1LL << 63);

int main() {
	llint n;
	cin >> n;
	hei(ll) a(n),s(n+1,0);
	llint sum = 0;
	rep(i, 0, n) {
		cin >> a[i];
	}
	for (llint i = n - 1; i >= 0; i--) {
		s[i] = s[i + 1] + a[i];
		s[i] %= mod;
	}
	ll ans = 0;
	rep(i, 0, n) {
		ans += a[i] * s[i+1] % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
