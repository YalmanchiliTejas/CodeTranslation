#include<bits/stdc++.h>
#include <iomanip>
#include <iostream>
using namespace std;
using ll = long long;
ll INF = 9999999999999999;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll max(ll a, ll b){
    if(a > b) return a;
    else return b;
}
 
ll min(ll a, ll b){
    if(a < b) return a;
    else return b;
}

int main(void){
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    int C2 = C*2;
    
    ll ans = 9999999999999999;
    for(int i = 0; i <= max(X,Y); i++){
        ll cost = C2*i + max((X-i)*A, 0) + max((Y-i)*B, 0);
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
