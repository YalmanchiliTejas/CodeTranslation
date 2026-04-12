#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

vector<ll> l;

ll func(ll n, ll x) {
    if (n == 0)
        return x;
    
    if (0 ==x)
        return 0;
    else if (1 <= x && x <= l[n-1]+1)
        return func(n-1, x-1);
    else if (x == l[n-1] + 2)
        return func(n-1, l[n-1]) + 1;
    else if (l[n-1] + 3 <= x && x <= 2*l[n-1] + 2)
        return func(n-1, l[n-1]) + 1 + func(n-1, x-l[n-1]-2);
    else 
        return 2 * func(n-1, l[n-1]) + 1;
}

int main() {
    ll n, x;    cin >> n >> x;

    l.resize(51, 1);
    for (int i = 0; i < 50; i++)
        l[i+1] = 2*l[i] + 3;

    cout << func(n, x) << endl;
    return 0;
}