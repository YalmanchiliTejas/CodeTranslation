#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cassert>

#define el_cucuy ios_base::sync_with_stdio(0), cout.tie(0); cin.tie(0);
#define llong long long
#define pb push_back
#define bpc __builtin_popcount
#define pii pair <int, int>
#define f first
#define s second

const llong mxn = 4 * 1e5 + 3;
const llong mod = 1e9 + 7;
const llong inf = 1e18 + 9;

using namespace std;

//int dx[]= {1,0,-1,0}; int dy[]= {0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0}; int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

llong n, m, a[mxn], dp[3001][3001], sum[mxn];

int main(){
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int sz = 2; sz <= n; sz ++){
        for (int l = 1; l <= n - sz + 1; l ++){
            llong r = l + sz - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[1][n];
    return 0;
}
