#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <ll> a;

ll calc(ll m){
    ll ret = 0;
    for(auto &i : a){
        if((i + m) % (n + 1) == n) return -1;
        ret += (i + m) / (n + 1);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll s = 0;
    for(auto &i : a) s += i;
    for(ll i = max(0LL, s - 100000) ; i <= s + 100000 ; i++){
        if(calc(i) == i) finish(i);
    }
}
