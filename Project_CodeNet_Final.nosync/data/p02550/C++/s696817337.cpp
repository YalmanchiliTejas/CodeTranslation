#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll N,X,mod; cin >> N >> X >> mod;
    vector<ll> lib(mod,-1);
    vector<ll> A(10000000,0);
    A[1] = X;
    ll line1;
    for(ll i=2; i<=10000000; i++) {
        A[i] = (A[i-1]*A[i-1])%mod;
        if(lib[A[i]]>0) {
            line1 = i;
            break;
        }
        else lib[A[i]] = i;
    }

    ll a=0,b=0,e=0;
    for(int i=1; i<=lib[A[line1]]-1; i++) a+=A[i];
    //cout << "a:" << a << endl;
    for(int i=lib[A[line1]]; i<=line1-1; i++) b+=A[i];
    //cout << "b:" << b << endl;
    ll y = (N-lib[A[line1]]+1)/(line1-lib[A[line1]]);
    //cout << "y:" << y << endl;
    ll c = y*b;
    //cout << "c:" << c << endl;
    ll z = (N-lib[A[line1]]+1)%(line1-lib[A[line1]]);
    //cout << "z:" << z << endl;
    ll d;
    if(z==0) d=0;
    else {
        //d = A[lib[A[line1]]+z-1];
        for(int i=lib[A[line1]]; i<=lib[A[line1]]+z-1; i++) e+=A[i];
    }

    ll ans = a+c+e;
    cout << ans << endl;
}