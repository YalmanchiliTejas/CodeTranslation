#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
struct edge { int to, cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = ~(1<<31);
const int MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int dp[100010];

int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i,n) cin >> a[i];
	reverse(a,a+n);

	rep(i,n) dp[i] = INF;

	rep(i,n){
		*upper_bound(dp,dp+n,a[i]) = a[i];
	}

	cout << lower_bound(dp,dp+n,INF)-dp << endl;

	return 0;
}