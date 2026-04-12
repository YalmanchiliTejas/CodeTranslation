#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }

int main() {
    int x;
    cin >> x;
    cout << ((x == 7 || x == 5 || x == 3) ? "YES" : "NO") << endl;
}