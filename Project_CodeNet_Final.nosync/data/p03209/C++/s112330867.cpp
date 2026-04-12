#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll an = 1;
ll pn = 1;
ll bn = 0;
vector<ll> a(51);
vector<ll> p(51);
vector<ll> b(51);
int f(){
    rep(j, 51){
//        cout << j << " k" << an << " p" << pn << " b" << bn << endl;
        a.at(j) = an;
        p.at(j) = pn;
        b.at(j) = bn;
        an = an*2 + 3;
        pn = pn*2 + 1;
        bn = bn*2 + 2;
    }
}
ll ans = 0;

ll sai(ll n, ll x){
//    cout << " ans:" << ans << " n:" << n << " x:" << x << endl;
    if(n == 1){
        if(x >= 2 && x <= 4){
            ans += x - 1;
        }else if(x == 5){
            ans += 3;
        }
        return 0;
    }
    if(x == 1){
        return 0;
    }else if(x == a.at(n)){
        ans += p.at(n);
        return 0;
    }else if(x == (a.at(n)+1)/2){
        ans += p.at(n-1) + 1;
        return 0;
    }else if(x < (a.at(n)+1)/2){
        sai(n-1, x-1);
        return 0;
    }else{
        ans += p.at(n-1) + 1;
        sai(n-1, x - (a.at(n)+1)/2);
        return 0;
    }
}

int main(){
    ll n, x;
    cin >> n >> x;
    f();
    sai(n, x);
    cout << ans << endl;
    return 0;
}