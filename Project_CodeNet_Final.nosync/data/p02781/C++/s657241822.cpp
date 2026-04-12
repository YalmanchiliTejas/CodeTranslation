#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define st first
#define nd second
#define endl '\n'
#define what_is(x) cerr << #x << " is " << x << endl;
#define what_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << e << ' '; cerr << '\n'; //vector, set
#define what_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << x[i] << ' '; cerr <<  '\n'; //n first element of array
#define cerr_pair(x) '{' << x.st << ", " << x.nd << '}'
#define pwhat_is(x) cerr << #x << " is " << cerr_pair(x) << endl;
#define pwhat_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << cerr_pair(e) << ' '; cerr << '\n'; //vector, set
#define pwhat_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << cerr_pair(x[i]) << ' '; cerr <<  '\n'; //n first element of array
#define int long long
// #define pow mypow

typedef pair<int,int> pii;
const int N = 1e5+5;
const int L = 100+5;
const int K = 3;
const int INF = 1e9+5;
const int MOD = 1e9+7;

string n;
int k;
int f[L][4];
int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> k;
	int stored_k = k;
	f[0][0] = 1; //else = 0
	int len = n.length();
	for(int i=1; i<=len; i++){
		for(int j=0; j<=K; j++){
			if (j == 0) f[i][0] = 1;
			else f[i][j] = 9*f[i-1][j-1] + f[i-1][j];
		}
	}
	int ans = 0;
	for(int i=0; i<len; i++){
		int d = n[i] - '0';
		for(int l=0; l<d; l++){  // left_most
			if (l==0) ans += f[len-i-1][k];
			else if(k) ans += f[len-i-1][k-1];
		}
		k -= (d > 0);
		if (k < 0) break;
	}
	int cnt_non_zeroes = 0;
	for(int i=0; i<len; i++) cnt_non_zeroes += (n[i] != '0');
	ans += (cnt_non_zeroes == stored_k);
	cout << ans << endl;
	
	return 0;
}
