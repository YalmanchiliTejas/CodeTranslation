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
    int h,w;
    cin>>h>>w;
    int cnt = 0;
    rep(i, h)
    {
        string s;
        cin>>s;
        rep(j,s.size()){
            if(s[j]=='#'){
                cnt++;
            }
        }
    }
    if(cnt==h+w-1){
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}