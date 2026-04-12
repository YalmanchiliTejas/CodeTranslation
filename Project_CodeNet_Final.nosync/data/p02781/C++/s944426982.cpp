#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

#define user spaesk
#define pi acos(-1)
#define int long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<int> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const int ths = 1LL << 40;
const int NN = 5e3 + 6;

const int maxN = 500007;

///154_e
///

string n;
int K;
int cache[110][110][2];

int dp(int i, int k, int ok) {


    if(i == n.size() and  k == K)
        return 1;

    if(i >= n.size())
        return 0;

    int &ans = cache[i][k][ok];

    if(ans != -1)
        return ans;

    ans = 0;

    for(int j = 0; j < 10; j ++) {
        if(ok == 1) {
            if(j != 0)
                ans += dp(i + 1, k + 1, 1);
            else
                ans += dp(i + 1, k, 1);
        }
        else {
            int x = n[i] - '0';
            if(j == 0) {
                if(x == 0)
                    ans += dp(i + 1, k, 0);
                else
                    ans += dp(i + 1, k, 1);
            }
            else if(j < x)  {
                ans += dp(i + 1, k + 1, 1);
            }
            else if(j == x)
                ans += dp(i + 1, k + 1, 0);
        }
    }
    return ans ;
}


void solve()
{

    memset(cache, -1, sizeof cache);
    cin>>n>>K;

    int ans = dp(0, 0, 0);
    cout<<ans;

    cout<<"\n";
    return ;
}

/*
*/

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
