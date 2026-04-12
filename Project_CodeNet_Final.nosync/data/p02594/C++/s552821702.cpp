#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mod 1000000007
typedef int integer;
#define int long long
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 0
#endif
using namespace std;

template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << ": " << arg1 << endl;
}

template<typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

int powmod(int a, int b) {
    int res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const integer NN = (int) 5e5 + 2;
int ar[NN];
int n, m;


integer main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if (n >= 30){
        cout << "Yes\n";
    } else cout << "No\n";

}
