#include <bits/stdc++.h>
#include <numeric>

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
#define LL long long
#define MOD 1000000007

//cout << (c)?"Yay!":":(" << endl;

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s == "AAA" || s=="BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
