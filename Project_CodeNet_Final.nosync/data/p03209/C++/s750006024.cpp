#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long
typedef vector<ll> vi;

ll Len[51],Pat[51];

ll make_bager(ll k, ll x){
    ll ans = 0;
    if(x == Len[k]) return Pat[k];

    // 下のバン
    x--;
    // 下のk-1バーガー
    if(x > 0){
        ll l = min(x, Len[k-1]);
        ans += make_bager(k-1, l);
        x -= l;
    }
    // 真ん中のパティ
    if(x > 0){
        ans++;
        x--;
    }
    // 上のk-1バーガー
    if(x > 0){
        ll l = min(x, Len[k-1]);
        ans += make_bager(k-1, l);
        x -= l;
    }
 
    return ans;
}

int main(){
    ll N, X;
    Len[0] = Pat[0] = 1;

    cin >> N >> X;
    for(ll i = 1; i <= N; i++){
        Len[i] = Len[i-1] * 2 + 3;
        Pat[i] = Pat[i-1] * 2 + 1;
    }

    cout << make_bager(N,X) << endl;
}
