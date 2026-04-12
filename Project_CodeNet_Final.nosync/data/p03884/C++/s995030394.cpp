#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

ll k;
vector<int> f;
long long dp[5000][8];
vector<long long> grand;

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 650; i++)
    {
        f.push_back(0);
        f.push_back(1);
        f.push_back(2);
        f.push_back(3);
        f.push_back(4);
        f.push_back(5);
        f.push_back(6);
    }
    dp[0][0] = 1;
    for (int i = 1; i < f.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }
        if (f[i] == 0) dp[i][0]++;
        else dp[i][f[i]] += dp[i - 1][f[i] - 1];
    }
    /*for (int i = 6; i < f.size(); i += 7)
    {
        cout << dp[i][6] << endl;
    }
    cout << f.size() << endl;
    cout << (ll)(1e18) / dp[f.size() - 1][6] << endl;*/
    long long k;
    cin >> k;
    for (int i = f.size() - 1; i >= 6; i-= 7)
    {
        grand.push_back(k / dp[i][6]);
        k %= dp[i][6];
    }
    reverse(all(grand));
    int t = 0;
    for (int i = 6; i < f.size(); i += 7)
    {
        cout << "FESTIVA";
        for (int j = 0; j < grand[t]; j++)
        {
            cout << "L";
        }
        t++;
    }
}
