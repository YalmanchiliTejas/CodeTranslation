#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> odds;
    vector<int> evens;
    rep(i, 0, n)
        if (i % 2 == 0)
            evens.push_back(a[i]);
        else
            odds.push_back(a[i]);

    if (n % 2 == 1)
    {
        reverse(evens.begin(), evens.end());
        rep(i, 0, evens.size())
            cout << evens[i] << ' ';
        rep(i, 0, odds.size())
            cout << odds[i] << ' ';
    }
    else
    {
        reverse(odds.begin(), odds.end());
        rep(i, 0, odds.size())
            cout << odds[i] << ' ';
        rep(i, 0, evens.size())
            cout << evens[i] << ' ';
    }
    cout << endl;
    return 0;
}