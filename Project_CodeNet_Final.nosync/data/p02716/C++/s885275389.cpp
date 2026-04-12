#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)

#define int long long
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }
template<class T>
ostream &operator<<(ostream &os,const vector<T> &v){
	for(int i = 0;i < v.size();i++) os << (i ? "," : "[") << v[i];
	os << "]";
	return os;
}

template<class T> T &chmin(T &a,const T &b){ return a = min(a,b); }
template<class T> T &chmax(T &a,const T &b){ return a = max(a,b); }

const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[200010],dp[200010][3];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < 3;j++) dp[i][j] = -INF;
	}
	dp[0][0] = 0;
	for(int i = 0;i < n / 2;i++){
		chmax(dp[i + 1][0],dp[i][0] + a[i * 2]);
		chmax(dp[i + 1][1],max(dp[i][0],dp[i][1]) + a[i * 2 + 1]);
		if(n % 2) chmax(dp[i + 1][2],max({dp[i][0],dp[i][1],dp[i][2]}) + a[i * 2 + 2]);
	}
	cout << max({dp[n / 2][0],dp[n / 2][1],dp[n / 2][2]}) << endl;
}