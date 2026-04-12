/*{{{*/
#include <bits/stdc++.h>
#ifdef _GLIBCXX_DEBUG
int c_;
#define cout (c_?cerr:cout)
#define dbg(...) {if (!c_)cerr<<"\033[96;1m";++c_;\
__VA_ARGS__;--c_;if(!c_)cerr<<"\033[0m";}
#else
#define dbg(...)
#endif
#define st first
#define nd second
#define dump(...) dbg(print(#__VA_ARGS__,'=',__VA_ARGS__))
#define all(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define range_dump(...) dbg(cerr<<#__VA_ARGS__<<':';range_print(__VA_ARGS__));
using namespace std; using ll = long long;
template< typename t > using V = vector< t >;
template< typename t > void print(const t& a){cout<<a<<'\n';}
template< typename t, typename... v > void print(const t& a, v&&... b)
{cout<<a<<' ';print(b...);}
template< typename t > void range_print(t a, const t& b)
{while (a!=b)cout<<(*a++)<<' ';cout << '\n';}
/*}}}*/



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;cin >> n >> m;
    V< pair< int, int > > ilo;

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        for (int k = 0; k < m; ++k)
            if (s[k] == '#')
                ilo.push_back({i, k});
    }

    for (auto& p : ilo)
        for (auto& q : ilo)
            if (not ((p.st <= q.st and p.nd <= q.nd) or
                (q.st <= p.st and q.nd <= p.nd)))
                return print("Impossible"), 0;

    print("Possible");
}