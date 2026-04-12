#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll cntp(ll n){
    if(n == 0) return 1LL;
    return 2 * cntp(n-1) + 1;
}

ll volm(ll n){
    if(n == 0) return 1LL;
    return 2 * volm(n-1) + 3;
}

ll f(ll n, ll x){
    if(n == 0){
        if(x == 0) return 0; // いくら n == 0 でも、x == 0 なら 0
        else return 1LL;
    }
    
    if(x == 1 || x == 0) return 0;
    else if(2 <= x && x <= volm(n-1) + 1){
        return f(n - 1, x - 1);
    }
    else if(volm(n-1) + 2 <= x && x <= volm(n)){
        return cntp(n-1) + 1 + f(n - 1, x - 2 - volm(n-1));
    }
}


int main(void){
    ll n, x;
    cin >> n >> x;
    cout << f(n, x) << endl;
    return 0;
}