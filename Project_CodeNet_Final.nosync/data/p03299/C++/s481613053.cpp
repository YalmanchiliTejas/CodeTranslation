#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const Int INF2 = Int(INF) * 5000;
const Int INF3 = Int(INF) * INF;
const int MAX = 100007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

int A[MAX];
Int bpow(Int a, Int k)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        k /= 2;
    }
    return res;
}

Int solve(int L, int R)
{
    if (L > R) return 1;

    if (L == R)
    {
        return bpow(2 , A[L]);
    }

    Int val1 = (bpow(2 , R - L + 1) - 2 + MOD) % MOD;
    FOR(i,L, R + 1)
    {
        int cnt = INF;
        if (i - 1 >= L) cnt = min(cnt , A[i] - A[i - 1]);
        if (i + 1 <= R) cnt = min(cnt , A[i] - A[i + 1]);
        if (cnt < 0) cnt = 0;
        val1 *= bpow(2 , cnt);
        val1 %= MOD;
    }

    Int val2 = 1;

    VI H;
    FOR(i,L,R + 1)
    {
        H.push_back(A[i]);
    }
    H.push_back(0);
    sort(ALL(H));
    H.resize(unique(ALL(H)) - H.begin());

    FOR(i,0,SZ(H) - 1)
    {
        int cnt = 0;

        bool st = false;

        FOR(j,L, R + 1)
        {
            if (A[j] > H[i])
            {
                st = true;
            } else
            {
                cnt += st;
                st = false;
            }
        }
        cnt += st;
        val2 *= bpow(2 , (Int)(H[i + 1] - H[i]) * cnt);
        val2 %= MOD;
    }

    cout << val1 << ' ' << val2 << endl;

    return val1 + val2;
}

Int dp[107];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt" , "w", stdout);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        cin >> A[i];
    }

    VI H;
    FOR(i,0,n)
    {
        H.push_back(A[i]);
    }
    H.push_back(0);
    sort(ALL(H));
    H.resize(unique(ALL(H)) - H.begin());

    vector<pair<PII, int> > C;

    FOR(i,0,SZ(H) - 1)
    {
        int cnt = 0;

        bool st = false;
        int L;
        FOR(j,0, n)
        {
            if (A[j] > H[i])
            {
                if (!st) {
                    st = true;
                    L = j;
                }
            } else
            {
                if (st)
                {
                    C.push_back(MP(MP(L , j - 1) , H[i + 1] - H[i] - (i == 0)));
                }
                st = false;
            }
        }
        if (st)
        {
            C.push_back(MP(MP(L , n - 1) , H[i + 1] - H[i] - (i == 0)));
        }
    }

//    FOR(i,0,SZ(C))
//    {
//        cout << C[i].first.first << ' ' << C[i].first.second << ' ' << C[i].second << endl;
//    }

    dp[0] = 1;

    FOR(i,0,n)
    {
        FOR(j,i,n)
        {
            Int v = 0;
            FOR(k,0,SZ(C))
            {
                if (C[k].first.first >= i && C[k].first.second <= j)
                    v += C[k].second;
            }

            dp[j + 1] = (dp[j + 1] + (1 + (i == 0)) * bpow(2 , v) * dp[i]) % MOD;


        }
    }

    cout << dp[n] << endl;


//    Int res = 1;
//
//    int last = 0;
//
//    FOR(i,0,n)
//    {
//        if (A[i] == 1)
//        {
//            res *= 2;
//            res %= MOD;
//            res *= solve(last , i - 1);
//            res %= MOD;
//            last = i + 1;
//        }
//    }
//    res *= solve(last , n - 1);
//    res %= MOD;
//
//    cout << res << endl;

}