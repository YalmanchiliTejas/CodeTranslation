#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> hum_layer(55,0);
vector<ll> pate_num(55, 0); //各層ごとのパティの枚数

ll eat_layer(int n, ll pos, ll sum){
    //cout << "n:" << n << " pos:" << pos << " sum: " << sum << ln;
    if(n == 1){
        sum += min((ll)3, pos);
        return sum;
    }
    ll layer = hum_layer[n], pate = pate_num[n];
    if(pos == 0) return sum;
    if(pos == layer-1) return (sum + pate);
    if(pos == (layer-1)/2) return (sum + pate / 2 + 1);

    if(pos > (layer-1)/2){
        pos -= layer/2+1;
        sum += pate / 2+1;
    } else{
        pos--;
    }
    return eat_layer(n-1, pos, sum);
}

int main() {
    ll n, x;
    cin >> n >> x; x--;
    
    ll num = 1;
    hum_layer[0] = 1;
    for(int i = 1; i <= 50; i++){
        num = num * 2 + 1;
        pate_num[i] = num;
        hum_layer[i] = hum_layer[i-1] * 2 + 3;
    }

    ll res = eat_layer(n, x, 0);
    cout << res << ln;
}

