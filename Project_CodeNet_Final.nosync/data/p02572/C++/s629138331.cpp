#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

int MOD_BIG = 1000000007;
int MOD_BIG2 = 998244353;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////

//////////////////////////////////////

int main() {
    
    int N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
        sum %= MOD_BIG;
    }
    ll ans = 0;
    REP(i, N) {
        sum += -A[i] + MOD_BIG;
        sum %= MOD_BIG;
        ans += A[i]*sum;
        ans %= MOD_BIG;
    }
    cout << ans << endl;
    
    return 0;
}
