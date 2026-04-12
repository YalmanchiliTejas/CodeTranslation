#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    int n;
    cin>>n;
    vector<int> mins(26,1000);
    rep(i,n){
        string s;
        cin >> s;
        vector<int> ss(26);
        rep(j, s.size())
        {
            ss[s[j] - 'a']++;
        }
        rep(j,26){
            chmin(mins[j], ss[j]);
        }
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    rep(i, 26)
    {
        rep(j,mins[i]){
            cout << alphabet.substr(i, 1);
        }
    }
    cout << endl;
    return 0;
}