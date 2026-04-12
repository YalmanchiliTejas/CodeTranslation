#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> l, p;

ll func(ll n, ll x) {
    if (n == 0)
        return x;

    if (x <= 1)
        return 0;
    else if (1 < x && x <= l[n-1]+1)
        return func(n-1, x-1);
    else if (x == l[n-1]+2)
        return p[n-1] + 1;
    else if (l[n-1]+2 < x && x <= 2*l[n-1]+2)
        return p[n-1] + func(n-1, x-l[n-1]-2) + 1;
    else 
        return 2*p[n-1] + 1;
}

int main() {
    ll n, x;    cin >> n >> x;
    l.resize(51, 1);
    p.resize(51, 1);
    for (int i = 0; i < 50; i++) {
        l[i+1] = 2*l[i]+3;
        p[i+1] = 2*p[i]+1;
    }

    cout << func(n, x) << endl;
    return 0;
}