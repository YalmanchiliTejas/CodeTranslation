#include <bits/stdc++.h>
using namespace std;


#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define print(x) cout << x << endl;
typedef long long ll;

constexpr ll INF = 1'010'000'000'000'000'017LL;\
constexpr ll MOD = 1'000'000'007LL;\
constexpr double EPS = 1e-12;\
constexpr double PI = 3.14159265358979323846;

int main()
{
    string S;
    cin >> S;
    if (S == "AAA" || S == "BBB") {
        print("No");
    } else {
        print("Yes");
    }
    return 0;
}