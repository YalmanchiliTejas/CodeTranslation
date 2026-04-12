/*  

    IITAPOORV094

/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
|                                        |
|   *******     *******     ********     |
|      |           |            |        |
|      |           |            |        |
|      |           |            |        |
|   *******     *******         |        |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

*/

 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MEM(a, b) memset(a, (b), sizeof(a))

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef map<int,int> MPI;
typedef set<int> SETI;
typedef multiset<int> MSETI;

ll dp[10001][101][2];


ll solve(string &k,ll D,ll d,ll pos,ll tght)
{
	ll ub=(tght) ? (k[pos]-'0') :9;

	if(dp[pos][d][tght]!=-1)
	{
		return(dp[pos][d][tght]);
	}
	if(pos==k.length()-1)
	{
		ll ans=0;
		forc(i,0,ub)
		{
			if(i%D==d)
			{
				ans++;
			}
		}
		return(ans);
	}
	
	ll ans=0;
	forc(i,0,ub)
	{
		ans=(ans+solve(k,D,(D+d-i%D)%D,pos+1,(tght)&&(i==ub)))%MOD;
	}
	return(dp[pos][d][tght]=ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string k;
    cin>>k;
    MEM(dp,-1);
    ll D;
    cin>>D;
    cout<<(MOD+solve(k,D,0,0,1)-1)%MOD;  //as zero is included
    return 0;
}
