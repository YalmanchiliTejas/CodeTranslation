#include <bits/stdc++.h>

#define ALL(container) (container).begin(), (container).end()
#define INF 1000000007
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll GCD (ll a, ll b) { return b ? GCD(b, a % b) : a; }

using namespace std;

int main()
{
    int X;
    cin >> X;
    string s = (X == 3 || X == 5 || X == 7) ? "YES" : "NO";
    cout << s;
    return 0;
}
