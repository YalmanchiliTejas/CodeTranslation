/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int  dp[105][5][2], k, n ; 
string  s ; 

int dpp(int idx, int len, int flag){ 
	if ( idx == n or len >= k ) 
		return k == len; 
	if (dp[idx][len][flag] != -1)  return  dp[idx][len][flag] ; 
	int sum = 0LL;
	int limit = (flag ? s[idx]-'0' : 9 ) ;  
	for (int i=0;i<=limit;i++){
		sum += dpp(idx+1, len+(i>0), flag && i==limit);
	}
	return dp[idx][len][flag] = sum ;
}

signed main()
{
    cin >> s >> k ; 
    n = sz(s) ; 
    memset (dp,-1,sizeof(dp)) ; 
    cout << dpp(0,0,1) << endl ; 
    return 0;
}
