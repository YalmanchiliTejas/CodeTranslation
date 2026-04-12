#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> a;
vector<ll> p;

ll f(ll n, ll x) {
    if(n==0)
        return 1;
    if(x==1)
        return 0;
    if(x <= 1 + a[n-1]) {
        return f(n-1,x-1);
    }
    if(x == a[n-1]+2) {
        return p[n-1] + 1;
    }
    return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
}

int main() {
    ll n,x; cin >> n >> x;
    a.push_back(1);
    p.push_back(1);
    for(int i = 1; i <= n; i++) {
        a.push_back(a[i-1]*2 + 3);
        p.push_back(p[i-1]*2 + 1);
    }

    cout << f(n, x) << endl;
}
