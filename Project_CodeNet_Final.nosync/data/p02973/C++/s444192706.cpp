#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;

int memo[100005];

int main()
{
    ciosup;
    int n;
    cin >> n;
    vint b(n);
    REP(i, n)
    {
        cin >> b[i];
    }
    multiset<int> s;
    s.insert(b[0]);
    FOR(i, 1, n)
    {
        if (b[i] <= *s.begin()){
            s.insert(b[i]);
        }else{
            auto ite = s.lower_bound(b[i]);
            --ite;
            s.erase(ite);
            s.insert(b[i]);
        }
    }
    cout << s.size() << endl;
}
