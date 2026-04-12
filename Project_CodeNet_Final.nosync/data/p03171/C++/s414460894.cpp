#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll  long long
#define PB push_back
#define ld long double
#define ff first
#define ss second
# define st(v) (v).begin(),(v).end()
#define   pr pair<int,int>
const int N = 1e5+4 , M=N,inf=(int)1e9;
const ll mod=1e9+7;
int fastAbs(int n) { return (n ^ (n >> 31)) - (n >> 31); }
ll multiply(ll a, ll b){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
int ans = INT_MAX;
map< pair<int,int> , int > mp;
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,-1,1,0};
int n ;
vector < ll > a(3004);
ll dp[3001][3001][2];
ll fun( int l , int r , int choice ){
	if(dp[l][r][choice]!=-1) return dp[l][r][choice];
	if(l>r)
		return 0 ;
	if(l==r)	return a[l];
	if(choice==0){
		dp[l][r][choice] = max(a[l]-fun(l+1,r,1),a[r]-fun(l,r-1,1));
		return dp[l][r][choice];
	}
	else{
		dp[l][r][choice] = max(a[l]-fun(l+1,r,0),a[r]-fun(l,r-1,0));
		return dp[l][r][choice];
	}
}
void solve(){
	cin >> n ;
	for( int i = 0 ;i < n;  i++)	cin >> a[i] ;
	for ( int i = 0 ; i < 3001 ; i++){
			for( int j = 0 ;j < 3001 ; j++){
				dp[i][j][0] = -1 ;
				dp[i][j][1] = -1;
			}
	}
	cout << fun(0,n-1,0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=1;
    //cin >> q;
    while(q--)
        solve();
}
