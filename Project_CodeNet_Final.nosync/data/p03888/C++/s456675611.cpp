#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = 1; i <= n; i++)
#define drep(i, n) for(int i = n-1; i >= 0; i--)
#define srep(i, s, t) for (int i = s; i < t; i++)
#define vi vector<int>
#define P pair<ll, ll>
int mod = 1'000'000'000 + 7;
struct edge {
    int to;
    ll cost;
};

void COME_LET_THE_GAMES_BEGIN() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
}

map<char, char> m;

int main() {
    COME_LET_THE_GAMES_BEGIN();
    double A, B;
    cin >> A >> B;
    cout << A * B / (A + B) << endl;
}