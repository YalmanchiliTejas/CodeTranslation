#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

using ll = long long;
using namespace std;
namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
ll M = 1000000007;
typedef pair<int, int> P;

typedef pair<ll, int> pli;

void solve()
{
    string a;
    cin >> a;
    int k;
    cin >> k;
    int len = a.size();
    vector<int> c(len);
    rep(i, len)
    {
        c[i] = i;
    }
    string s;
    rep(i, len)
    {
        s += '0';
    }
    int ans = 0;
    if (k == 3)
    {
        rep(i, len)
        {
            FOR(j, i + 1, len)
            {
                FOR(p, j + 1, len)
                {
                    string t = s;
                    rep(l, 9)
                    {
                        rep(m, 9)
                        {
                            rep(o, 9)
                            {
                                t[i] = '0' + l + 1;

                                t[j] = '0' + m + 1;
                                t[p] = '0' + o + 1;
                               // cout << t << endl;
                                if (t <= a)
                                {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (k == 2)
    {
        rep(i, len)
        {
            FOR(j, i + 1, len)
            {

                string t = s;
                rep(l, 9)
                {
                    rep(m, 9)
                    {

                        t[i] = '0' + l + 1;

                        t[j] = '0' + m + 1;
                      //  cout << t << endl;
                        if (t <= a)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    else
    {
        rep(i, len)
        {

            string t = s;
            rep(l, 9)
            {

                t[i] = '0' + l + 1;

                //cout << t << endl;
                if (t <= a)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
}