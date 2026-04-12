#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

string burger_gen ( int n ) {
    if ( n == 0 ) return "P";
    return "B"+burger_gen(n-1)+"P"+burger_gen(n-1)+"B";
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> p_num(n+1);
    vector<ll> total_num(n+1);
    p_num[0] = 1;
    total_num[0] = 1;
    for ( int i = 1; i <= n; ++i ) {
        p_num[i] = p_num[i-1] * 2 + 1;
        total_num[i] = total_num[i-1] * 2 + 3;
    }
    ll ans = 0;
    for ( int i = n; i >= 0; --i ) {
        if ( x == 0 ) break;
        if ( x == total_num[i] ) {
            ans += p_num[i];
            break;
        }
//        if ( x == 1 ) {
//            break;
//        }
        if ( x <= 1LL + total_num[i-1] ) {
            --x;
        }
        else {
            ans += 1LL + p_num[i-1];
            x -= 1LL + total_num[i-1] + 1LL;
        }
    }
    cout << ans << endl;
    return 0;
}
