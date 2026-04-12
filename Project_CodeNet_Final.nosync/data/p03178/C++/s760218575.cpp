/*author* Priyanshu Shrivastav (from IIT Palakkad) *
 * *_ __ ___  _ ______ ___  _ ____   ___  ___| |_  *
 * | '_ ` _ \| '__/ __/ _ \| '_ \ \ / / |/ __| __| *
 * | | | | | | | | (_| (_) | | | \ V /| | (__| |_  *
 * |_| |_| |_|_|(_)___\___/|_| |_|\_/ |_|\___|\__| *
When I wrote this, only God and I understood what I was doing
 ** * * * * * * * Now, only God knows * * * * * * */
#include         <bits/stdc++.h>
using namespace std;
#ifndef CONVICTION
#pragma GCC      optimize ("Ofast")
#pragma GCC      optimize ("unroll-loops")
#pragma GCC      target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define IOS      ios_base::sync_with_stdio(false); cin.tie (nullptr)
#define PREC     cout.precision (10); cout << fixed
#define bg(x)    " [ " << #x << " : " << (x) << " ] "
#define x        first
#define y        second
using ll = long long;
using ff = long double;
using pii = pair<int,int>;

#define debug(args...) { \
   /* WARNING : do NOT compile this debug func calls with following flags: // \
    * // -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2*/ \
   string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
   stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); \
}
void err(istream_iterator<string> it) { it->empty();
   cerr << " (Line : " << __LINE__ << ")" << '\n';
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
   cerr << fixed << setprecision(15) << " [ " <<  *it << " : " << a  << " ] "<< ' ';
   err(++it, args...);
}

const int N = (int)1e4 + 10, S = 104;
const int MOD = (int)1e9 + 7;

int dp[N][S][2];
int n, d;
string s;

inline int add (int a, int b) {
   return (a + b)%MOD;
}

void solve() {
   n = (int)s.size();
   s = ' ' + s;

   for (int dg = 0; dg < s[1] - '0'; ++dg)
      dp[1][dg % d][1] += 1;

   dp[1][(s[1] - '0')%d][0] += 1;

   for (int pos = 2; pos <= n; ++pos) {
      for (int rem = 0; rem < d; ++rem) {
         for (bool res_ : {false, true}) {
            int mx_digit = 9;
            if (!res_)
            {
               mx_digit = s[pos] - '0';
            }
            for (int dg = 0; dg <= mx_digit; ++dg) {
               bool res_now = (res_ || (dg < s[pos] - '0'));
               dp[pos][(rem + dg) % d][res_now] =
                  add(dp[pos][(rem + dg) % d][res_now], dp[pos - 1][rem][res_]);
            }
         }
      }
   }
   cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD << '\n';
}

signed main() {
   IOS; PREC;
   cin >> s >> d;
   solve();

   return EXIT_SUCCESS;
}
