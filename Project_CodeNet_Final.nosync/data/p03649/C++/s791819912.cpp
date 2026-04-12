#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#define BIT(nr) (1ULL << (nr))
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }


using namespace std;

int N;
void proc(int v[], int target, int count) {
    rep(i, N) {
        if (i == target) {
            v[i] -= N * count;
        }
        else {
            v[i] += count;
        }
    }
}

bool isEnd(vector<int>& v) {
    int N = v.size();
    bool end = true;
    for (int i : v) {
        if (i >= N) {
            end = false;
        }
    }
    return end;
}

int a[51];

signed main() {

    cin >> N;
    rep(i, N) {
        cin >> a[i];
    }

    int ans = 0;
    rep(i, 15000000) {
        rep(j, N) {
            if (a[j] >= N) {
                int count = a[j] / N;
                ans += count;
                a[j] -= count*N;
                rep(k, N) {
                    if (j != k) a[k] += count;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
