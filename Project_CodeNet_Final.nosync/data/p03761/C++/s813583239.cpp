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
	int n; cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	vvi a(n,vi(26));
	rep(i,n)rep(j,s[i].size()){
		int x = s[i][j] - 'a';
		a[i][x]++;
	}
	vi b(26,INF);
	rep(x,26){
		int mn = INF;
		rep(i,n) mn = min(mn,a[i][x]);
		b[x] = mn;
	}
	string ans;
	rep(x,26){
		char c = 'a'+x;
		int num = b[x];
		rep(i,num) ans += c;
	}
	cout << ans << endl;
}
