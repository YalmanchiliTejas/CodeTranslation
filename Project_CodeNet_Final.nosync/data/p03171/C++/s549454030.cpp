#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;



/////////////////////////////////////////////

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

////////////////////////////////

#define int long long

const int N = 3010;
int dp[N][N];

int calc(int l , int r , int turn , vector<int> &a){

	if(l > r)
		return 0;

	int &ans = dp[l][r];
	if(ans!=-1)
		return ans;

	int val = 0;
	//debug(l , r);
	if(turn ==0)
		return dp[l][r] = max(a[l] + calc(l+1 , r , turn^1 , a) , a[r] + calc(l , r-1 , turn^1 , a));
	else return dp[l][r] = min(calc(l+1 , r , turn^1 , a) , calc(l , r-1 , turn^1 , a));
}

void solve(){

	int n;
	cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0 ; i < n ; ++i){

		cin>>a[i];
		sum += a[i];
	}

	memset(dp , -1 , sizeof dp);

	int x = calc(0 , n-1 , 0 , a);
	int y = sum - x;
	//debug(x);
	cout<<x - y<<endl;
}

signed main(){

    fast;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}




