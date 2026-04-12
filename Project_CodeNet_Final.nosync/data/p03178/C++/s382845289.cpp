#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<climits>
#include<random>
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

const int mod = 1e9 + 7;
const int N = 10001;
int n;
int x;
string s;
int dp[N][10][2][100];
// f is zero means we can do anything .
// f is not zero means we are limited .
int calc(int pos ,int val , int f , int sum){

	if(pos==n){

		return (sum==0);
	}

	int &ans = dp[pos][val][f][sum];

	if(ans!=-1)
		return ans;

	int lim = 9;

	if(f==1)
		lim = s[pos]-'0';
	ans = 0;
	for(int i = 0 ; i <= lim ; ++i){

		if(f==0)
			ans += calc(pos+1 , i , 0 , (sum+i)%x);
		else if(i==lim && f==1)
			ans += calc(pos + 1 , i , 1 , (sum + i)%x);
		else ans += calc(pos+1 , i , 0 , (sum + i)%x);

		ans%=mod;
	}

	return ans;

}

void solve(){

	memset(dp , -1 , sizeof dp);

	cin>>s;

	n = s.size();

	cin>>x;


	int ans = calc(0 , 0 , 1 , 0);

	ans += 5*mod;

	--ans;
	ans%=mod;

	cout<<ans<<endl;
}
 
signed main(){
 
    fast;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}
