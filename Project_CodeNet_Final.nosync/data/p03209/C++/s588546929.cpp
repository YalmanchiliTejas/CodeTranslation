#include <bits/stdc++.h>
using namespace std;

using ll=long long;
vector<ll> l(0,0),p(0,0);

ll cal(ll x, ll n) {
    if(n == 0)
        return (x>0 ? 1 : 0);
    else if(x <= 1+l.at(n-1))
        return cal(x-1, n-1);
    else
        return p.at(n-1) + 1 + cal(x-2-l.at(n-1), n-1);
}

int main() {
    ll N,i,X;
    cin >> N >> X;

    l.resize(N+1);
    p.resize(N+1);
    l.at(0)=1, p.at(0)=1;
    
    for(i=1; i<N+1; i++) {
        l.at(i) = l.at(i-1)*2 + 3;
        p.at(i) = p.at(i-1)*2 + 1;
    }

    cout << cal(X,N) << endl;
}