#include <bits/stdc++.h>
#define FOR(i, begin, end) for(ll i = (begin); i < (end); i++)
#define rep(i, n) FOR(i, 0, n)
using ll = long long;
using namespace std;
#define all(x) (x).begin(),(x).end()
using pii = pair<int, int>;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main(int argc, char const *argv[])
{
    unordered_set<char> s;
    string ss;
    cin >> ss;
    rep(i, 3) {
        s.insert(ss[i]);
    }
    if(s.size() == 2) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
