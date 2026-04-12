#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------
const double pi = 3.14159265358979323846264;

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> a(4, vector<ll>(n + 2));
    a[0][0] = 0;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = 1;
    a[2][0] = 1;
    a[2][1] = 0;
    a[3][0] = 1;
    a[3][1] = 1;
    for (ll j = 0; j < 4; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (a[j][i] == 0)
            {
                if (s[i % n] == 'o')
                {
                    a[j][i + 1] = a[j][i - 1];
                }
                else
                {
                    a[j][i + 1] = (a[j][i - 1] + 1) % 2;
                }
            }
            if (a[j][i] == 1)
            {
                if (s[i % n] == 'o')
                {
                    a[j][i + 1] = (a[j][i - 1] + 1) % 2;
                }
                else
                {
                    a[j][i + 1] = a[j][i - 1];
                }
            }
        }
    }
    for (ll j = 0; j < 4; j++)
    {
        if (a[j][n] == a[j][0] && a[j][n + 1] == a[j][1])
        {
            for (ll i = 0; i < n; i++)
            {
                if (a[j][i] == 0)
                {
                    cout << "S";
                }
                else
                {
                    cout << "W";
                }
            }
            cout << endl;
            break;
        }
        if (j == 3)
        {
            cout << -1 << endl;
        }
    }
}