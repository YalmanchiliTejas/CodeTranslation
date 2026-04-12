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
const int N = 2*1e5 +5 ;
const int mod = 1e9 + 7 ;
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

void solve()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for(auto &it : a) cin >> it ;
	int dp[n][n][2] = {} ;
	for(int i = 0 ; i < n ; ++i) 
		dp[i][i][0] = a[i], dp[i][i][1] = -a[i]; 
	
	for(int k = 2 ; k <= n;  ++k){	
		for(int l = 0 ; l + k - 1 < n ; ++l){
			int r = l + k - 1 ;
			dp[l][r][0] = max(dp[l+1][r][1] + a[l], dp[l][r-1][1] + a[r]); 			
			dp[l][r][1] = min(dp[l+1][r][0] - a[l], dp[l][r-1][0] - a[r]); 
		}
	}
	cout << dp[0][n-1][0] ;
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
