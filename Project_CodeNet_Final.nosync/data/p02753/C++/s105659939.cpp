#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    string S = in<string>();
    char A = S[0];
    bool ok = 1;
    if(S[1] != A)ok = 0;
    if(S[2] != A)ok = 0;
    if(S[1] != S[2])ok = 0;
    cout << (ok ? "No" : "Yes") << "\n";
}