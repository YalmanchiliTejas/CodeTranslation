#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <string.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <ctime>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535897932384626433832795l
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define deci(n) cout<<fixed<<setprecision(n);
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define ALPHA 27
#define ll long long int
#define ld long double
#define mmset(arr, n) memset(arr, n, sizeof arr)
#define debug(x) cerr << '#' << ' ' << x << '\n'
#define len(s) s.length()
#define ForA(i,a,b) for(int i = a; i < b; i++)
#define ForA1(i,a,b) for(int i = b - 1; i >= a; i--)
#define ForB1(i,a,b) for(int i = b; i > a; i--)
#define ForB(i,a,b) for(int i = a; i <= b; i++)
#define INT_SIZE 18 
#define maxn 3010
#define Maxn 100010

using namespace std;

const ll INF = (ll)(8e18);
const ll MOD = 1000000007;

ll a[maxn], dp[maxn][maxn], prefix[maxn];

int main()
{
    IOS;        
    ll n; cin >> n;
    ForB(i,1,n) cin >> a[i];
    ForB(i,1,n) prefix[i] += prefix[i - 1] + a[i];
    ForB(i,1,n) dp[i][i] = a[i];
    ForB(i,2,n){
        ForB(j,1,n - i + 1){
            int l = i + j - 1;
            dp[j][l] = max(dp[j][l], a[l] + 
                          prefix[l - 1] - prefix[j - 1] - dp[j][l - 1]); 
            dp[j][l] = max(dp[j][l], a[j] + 
                          prefix[l] - prefix[j] - dp[j + 1][l]);                
        }
    }
    cout <<  dp[1][n] + dp[1][n] - prefix[n] << '\n';
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0 ;
}
