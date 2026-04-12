#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<assert.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
const ll mod=1000000007;
const double PI = acos(-1.0);
const double epsilon = PI / 180.0;//角度转弧度 
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N = 2e3+10, M = 1e6+10;
struct TIII {
	int x, y, z;
};
int n;
int a[N * 3]; 
int dp[N][N];
int maxa[N];
int mx, ex;
void init() {
	memset(dp, -INF, sizeof dp);
	memset(maxa, -INF, sizeof maxa);
	mx = 0;
	ex = 0;
}
int main() {
	init();
	cin>>n;
	for(int i = 1;i <= n * 3;i++) cin>>a[i];
	dp[a[1]][a[2]] = 0;
	dp[a[2]][a[1]] = 0;
	maxa[a[1]] = 0;
	maxa[a[2]] = 0;
	vector<TIII> upd;
	for(int i = 3;i <= n * 3;i += 3) {
		int x = a[i], y = a[i + 1], z = a[i + 2];
		if(x == y&&y == z) {
			ex++;
			continue;
		}
		for(int j = 0;j < 3;j++) {
			int m = max(dp[z][z] + 1, mx);
			upd.pb({x, y, m});
			for(int k = 1;k <= n;k++) {
				int m = maxa[k];
				if(x == y) m = max(m, dp[k][x] + 1);
				upd.pb({k, z, m});
			}
			swap(x, y);swap(y, z);
		}
		for(int k = 0;k < upd.size();k++) {
			int x = upd[k].x, y = upd[k].y, m = upd[k].z;
			mx = max(mx, m);
			maxa[x] = max(maxa[x], m);
			maxa[y] = max(maxa[y], m);
			dp[x][y] = max(dp[x][y], m);
			dp[y][x] = max(dp[y][x], m);
		}
		upd.clear();
	}
	//cout<<mx<<"\n";
	cout<<mx + ex<<"\n";
	return 0;
}