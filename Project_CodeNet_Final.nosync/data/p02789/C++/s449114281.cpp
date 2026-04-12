#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int n, m;
    cin >> n >> m;
    if (n == m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
