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
    set<char> st;
    rep(i, 3) {
        char c; cin >> c;
        st.insert(c);
    }

    cout << (st.size() > 1 ? "Yes" : "No") << endl;
    return 0;
}