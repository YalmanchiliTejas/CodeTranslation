#include <bits/stdc++.h>
using namespace std;
typedef int int__;
#define int long long
#define pb push_back
#define pi pair<int,int>
#define vpi vector<pi>
#define vi vector<int>
#define vvi vector<vi>
#define fi first
#define se second
#define forn(i, n)for(int i=0;i<int__(n);i++) 
#define sz(a)int__(a.size())
template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a){return out << "(" << a.first << ", " << a.second << ")";}
template<class A>ostream& operator<<(ostream& out,const vector<A>&v){out<<"[";forn(i,sz(v)){if(i)out<<", ";out<<v[i];}return out<<"]";}
const int MAX = 1e9 + 100;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int Mod(int x){const int mm=1e9 + 7;x%=mm;if(x<0)x+=mm;return x;}
int Pow(int x,int n){if(n==0)return 1;int t=Pow(x,n/2);t=Mod(t*t);if(n&1)t=Mod(t*x);return t;}
#define watch(x) cout << #x << " : " << x << endl;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}

int dp[3005][3005][2] = {0};

int__ main() {
	fast;
	int n; cin >> n;
	vi a(n);

	for(int i=0;i<n;i++) {cin >> a[i]; dp[i][i][0] = a[i]; dp[i][i][1] = -a[i];}

	for(int i=n-1;i>=0;i--) {
		for(int j=i+1;j<n;j++) {
			dp[i][j][0] = max(a[i] + dp[i+1][j][1],a[j] + dp[i][j-1][1]);
			dp[i][j][1] = min(-a[i] + dp[i+1][j][0],-a[j] + dp[i][j-1][0]);
		}
	}

	cout << dp[0][n-1][0] << endl;
}