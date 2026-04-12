#include "bits/stdc++.h"

#define ll long long

using namespace std;

ll n, k, res = 0;
int main(){
    cin >> n >> k;
    for(ll i = k + 1; i <= n; ++i){
        res += max(n%i - k + 1, 0LL);
        if(!k) res--;
        res += n/i * (i - k);
    }
    cout << res;
    return 0;
}