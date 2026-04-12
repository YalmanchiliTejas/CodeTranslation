#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(ll i=0;i<(n);i++)

using namespace std;


int main(){
    ll n, k;
    cin >> n >> k;
    
    ll t = 0;
    rep(b, n+1){
        if(b <= k)  continue;

        ll r = n/b;
        ll d = b-k;

        t += r*d;

        t += max(0ll, (n%b)+1 - k);

        if(k == 0)  t--;
    }

    cout << t << endl;


    return 0;
}
