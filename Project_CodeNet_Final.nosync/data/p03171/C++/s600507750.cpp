
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int MOD = 1000000007;

LL dp[3000][3000]; // [head][tail] => max diff
bool done[3000][3000]; // true when the head-tail pair already cached
int a[3000];


LL solve(int head, int tail, int sign) 
{
    LL ret = dp[head][tail];    
    if (!done[head][tail]) {
        if (head == tail) {
            ret = sign * a[head]; 
        } else {
            LL headVer = sign * a[head] + solve(head+1, tail, 0-sign);
            LL tailVer = sign * a[tail] + solve(head, tail-1, 0-sign);
            if (sign * headVer < sign * tailVer) {
                ret = tailVer;
            } else {
                ret = headVer;
            }
            // cout << head << ", " << tail << " => " << headVer << ", " << tailVer << " => " << ret << endl;
        }
        dp[head][tail] = ret;
        done[head][tail] = true;
    }    
    return ret;
}


int main()
{
    int N;
    cin >> N;

    rep(i, N) cin >> a[i];

    cout << solve(0, N-1, 1) << endl;

    return 0;
}
