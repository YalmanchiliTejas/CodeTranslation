#include <bits/stdc++.h>

#define TYPE(c)   remove_reference_t<decltype(c)>
#define REP(i, n) for(TYPE(n) i = 0; i < n; i++)
#define FOR(v, c) for(TYPE(c.begin()) v = c.begin(); v != c.end(); v++)
#define ALL(c)    c.begin(), c.end()
#define SORT(c)   sort(ALL(c))
#define RSORT(c)  sort(ALL(c), greater<TYPE(c)::value_type>())
#define UNIQUE(c) c.erase(unique(ALL(c)), c.end())

using namespace std;
using ll = long long;

constexpr int MOD  = (int)1e9 + 7;
constexpr int INF  = (int)1e9 + 1;
constexpr ll  LINF = (ll)1e18 + 1;
template<typename T> constexpr bool chmax(T& a, const T& b)
{ if(a < b) { a = b; return true; } else { return false; } }
template<typename T> constexpr bool chmin(T& a, const T& b)
{ if(b < a) { a = b; return true; } else { return false; } }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T>& p)
{ return os << "(" << p.first << "," << p.second << ")"; }
ostream& operator<<(ostream &os, const string& s)
{ FOR(v, s) os << *v; return os; }
template<typename T> auto operator<<(ostream& os, const T& t)
    -> typename conditional<true, ostream&, decltype(*t.begin())>::type
{ os << "["; FOR(v, t) { if(v != t.begin()) os << ","; os << *v; } os << "]"; return os; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    REP(i, N) {
        std::cin >> A[i];
    }

    SORT(A);

    auto calc = [&](int base, int mod = 0) -> ll {
                    int r_index = 0;
                    int l_index = N - 1;
                    vector<int> table(N, 0);
                    REP(i, N / 2 + 1) {
                        auto f = [&](int from, int to) {
                                     if(from < 0 || N <= from || to < 0 || N <= to) {
                                         return false;
                                     }
                                     else {
                                         table[to] = A[from];
                                         return true;
                                     }
                                 };
                        if(i == 0) {
                            if(mod == 1) {
                                f(r_index, base);
                                r_index++;
                            }
                            else {
                                f(l_index, base);
                                l_index--;
                            }
                        }
                        else if(i % 2 == mod) {
                            auto flag1 = f(l_index, base + i);
                            if(flag1) l_index--;
                            auto flag2 = f(l_index, base - i);
                            if(flag2) l_index--;
                            if(!(flag1 && flag2)) break;
                        }
                        else {
                            auto flag1 = f(r_index, base + i);
                            if(flag1) r_index++;
                            auto flag2 = f(r_index, base - i);
                            if(flag2) r_index++;
                            if(!(flag1 && flag2)) break;
                        }
                    }

                    ll ans = 0;
                    REP(i, N - 1) {
                        ans += abs(table[i] - table[i + 1]);
                    }
                    return ans;
                };
    std::cout << (N % 2 == 0 ?
                  max({calc(N / 2, 1), calc(N / 2, 0), calc(N / 2 - 1, 1), calc(N / 2 - 1, 0)}) :
                  max(calc(N / 2, 1), calc(N / 2, 0))) << std::endl;

    return 0;
}
