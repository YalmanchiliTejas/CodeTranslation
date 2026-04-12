#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
ll n , k;

ll tot[N] , p[N];

ll f(ll n , ll x) {
    if(n == 0) {
        if(x <= 0)
            return 0;
        else
            return 1;
    }

    if(x <= tot[n - 1] + 1) {
        return f(n - 1 , x - 1);
    }
    else return 1ll*(p[n - 1] + 1 + f(n - 1, x - tot[n - 1] - 2));

}

int main(){
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> n >> k;
    tot[0] = 1;
    p[0] = 1;
    for(int i = 1 ; i <= n ; i ++) {
        tot[i] = tot[i - 1]*2 + 3*1ll;
        p[i] = p[i - 1]*2 + 1*1ll;
    }

    cout << f(n , k);
}