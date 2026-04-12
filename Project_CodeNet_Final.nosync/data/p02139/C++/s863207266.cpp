#include <bits/stdc++.h>

#define rep(n) for(ll i=0;i<n;i++)

using namespace std;

typedef long long ll;

int main(){
    ll n, q;
    cin >> n >> q;

    ll query, k, d = 0LL;
    rep(q){
        cin >> query >> k;

        if(query == 0LL){
            cout << (k-1+d)%n + 1LL << endl;
        }else{
            d += k;
        }
    }

    return 0;
}

