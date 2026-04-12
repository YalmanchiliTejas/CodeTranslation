#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n; cin >> n;
    /*
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    set<char> _ans(s[0].begin(), s[0].end());
    rep(i, n) {
        set<char> cur(s[i].begin(), s[i].end());
        string str(100, 'A');
        auto it = set_intersection(all(_ans), all(cur), str.begin());
        str.resize(it - str.begin());
        _ans = set<char>(str.begin(), str.end());
    }
    */
   vector<map<char, ll>> s(n);
   rep(i, n) {
       string _s; cin >> _s;
       for (auto elem : _s) {
           s[i][elem]++;
       }
   }

    map<char, ll> citems = s[0];
   for (size_t i = 1; i < s.size(); i++)
   {
       map<char, ll> _citems;
       for (auto elem : s[i]) {
           if (citems.find(elem.first) != citems.end()) {
               _citems[elem.first] = min(citems[elem.first], elem.second);
           }
       }
       citems = _citems;
   }
   
   for (auto elem : citems) {
       cout << string(elem.second, elem.first);
   }
   cout << endl;

    return 0;
}