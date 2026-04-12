#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ll num[60];
ll num_p[60];

ll calc(ll n, ll x){
    if(x == 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(floor(num[n] / 2.0) >= x){
        return calc(n - 1, x - 1);
    }else if(ceil(num[n] / 2.0) <= x){
        return calc(n - 1, x - ceil(num[n] / 2.0)) + num_p[n-1] + 1;
    }
}

int main(void){
    ll n, x;
    cin >> n >> x;

    num[0] = 1;
    num_p[0] = 1;
    rep(i, 1, 51){
        num[i] = 2 * num[i-1] + 3;
        num_p[i] = 2 * num_p[i-1] + 1;
    }

    ll ans = calc(n, x);
    cout << ans << endl;
}
