#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
L(0) := P
L(n) := B L(n-1) P L(n-1) B
*/

ll f(int n){
    return n==0 ? 1 : f(n-1)*2+3;
}

ll g(int n){
    return n==0 ? 1 : g(n-1)*2+1;
}

ll calc(int n, ll x){
    if(x<=0) return 0;
    if(n==0){
        // assert(x==1);
        return 1;
    }
    ll fn = f(n);
    if(x > fn/2) return g(n-1) + 1 + calc(n-1, x - (fn/2+1));
    else return calc(n-1, x-1);
}

int main(void){
    int n;
    ll x;
    cin >> n >> x;
    cout << calc(n, x) << endl;
    return 0;
}
