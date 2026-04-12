#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define pdump(p) cout<<" "<<#p<<"=("<<p.fst<<","<<p.snd<<")"
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std; using lint = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<lint, lint>;

// べき乗の剰余
lint modpow(lint x, lint y, lint m) {
    if (y == 0) return 1;
    lint res = modpow(x, y / 2, m);
    return res * res % m * (y & 1 ? x : 1) % m;
}

lint an(lint n) {
    const lint MOD = 1e18;
    return modpow(2, n+2, MOD) - 3;
}

lint bn(lint n) {
    const lint MOD = 1e18;
    return modpow(2, n+1, MOD) - 1;
}

lint rec(lint n, lint x) {
    if (n==0) return 1;
    
    if (x == 1) return 0;
    if (1 <= x and x <= 1+an(n-1)) return rec(n-1, x-1);
    if (x == 2+an(n-1)) return bn(n-1)+1;
    //dump(n); dump(2+an(n-1)); dump(x); dump(2+2*an(n-1)); dump(x-(an(n-1)+2)); el;
    if (3+an(n-1) <= x and x <=2+2*an(n-1)) return bn(n-1)+1+rec(n-1, x-(an(n-1)+2));
    if (x == 3+2*an(n-1)) return 2*bn(n-1)+1;
    assert (false);
    return -1;
}

int main(void) {
    lint n, x;
    cin >> n >> x;
    
    cout << rec(n, x) << endl;
}