#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
long long mod = 1000000007;
long long modpow(long long m,long long n){
    long long res = 1;
    if(n > 0){
        res = modpow(m,n / 2);
        if(n % 2 == 0){
            res = (res * res) % mod;
        }
        else{
            res = (((res * res) % mod) * m) % mod;
        }
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll wa = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        wa += a[i];
    }
    ll res = 0;
    for(int i = 0;i < n;i++){
        ll now = wa - a[i];
        now %= mod;
        res += a[i] * now;
        res %= mod;
    }
    res *= modpow(2,mod-2);
    res %= mod;
    cout << res << endl;
}