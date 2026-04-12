//Program.cpp
//Author : Aaryan Srivastava 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#define pb push_back
#define popb pop_back
#define ull unsigned long long  
#define beg begin
#define mp make_pair
#define pii pair<int, int>
#define piii pair<pii,int>
#define rep(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second 
#define fill(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using ll = long long;
#define int ll
const int N = 3005 ;
const int mod = 1e9 + 5 ;
const int inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace std;

#ifdef AaryanS
#define mycout cout
#define mycerr cerr 
#endif

#ifndef AaryanS
#define mycout if(false) cout
#define mycerr if(false) cerr
#define AaryanS 0 
#endif

int dp[N][N][2] ;

void solve(){
	int n ;
	cin >> n ;
	int arr[n] ;
	fill(dp,0LL) ;
	rep(i,n){
			cin >> arr[i] ;
		rep(j,2){
			dp[i][i][j] = (j ? 1 : -1) * arr[i] ; 
		}
	}
	repA(j,2,n)						
		rep(i,n){
			if(i+j-1 >= n)
				continue ;
			mycerr << "state : " << i << " " << i+j-1 << " -> depends on : (" 
			<< dp[i][i+j-2][0] << "," << dp[i][i+j-2][1] << ") [" << i << "," 
					<< i+j-2 << "] (" << dp[i+1][i+j-1][0] << "," << dp[i+1][i+j-1][1] 
					<< ") [" << i+1 << "," << i+j-1 << "]\n" ; 
			dp[i][i+j-1][1] = max(dp[i][i+j-2][0] + arr[i+j-1] , dp[i+1][i+j-1][0] + arr[i]);
			dp[i][i+j-1][0] = min(dp[i][i+j-2][1] - arr[i+j-1] , dp[i+1][i+j-1][1] - arr[i]);
		}
	rep(i,n){
		rep(j,n)
			mycout << "(" << dp[i][j][0] << "," << dp[i][j][1] << ") " ;
		cout << endl ;
	}
	cout << dp[0][n-1][1] ;
}   

int32_t main(int32_t argc, char *argv[])
{
    double t1 = clock() ;
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case " << t << ":\n" ;
        solve();
    }
    mycerr << "Time : " << 1000 *(clock() - t1)/CLOCKS_PER_SEC << " ms\n" ;
    return 0;

}