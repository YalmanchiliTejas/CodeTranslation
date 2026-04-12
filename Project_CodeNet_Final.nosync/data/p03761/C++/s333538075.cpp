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
#include <math.h>
#include <assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INF = 1000000007;
const int mod = 1000000007;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

//----------------------------------------------------------------

int main()
{
    int n;
    cin >> n;
    string s;
    vector<long long> a(150), b(150);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        b[s.at(i)] += 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            a[s.at(j)] += 1;
        }
        for (int j = 0; j < 150; j++)
        {
            b[j] = min(b[j], a[j]);
        }
        for (int j = 0; j < 150; j++)
        {
            a[j] = 0;
        }
    }
    for (int i = 0; i < 150; i++)
    {
        if (b[i])
        {
            for (int j = 0; j < b[i]; j++)
            {
                cout << (char)i;
            }
        }
    }
}
