#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << (x) << endl;
#define INF (1e9)
#define add_mod(a, b, x) ( (ll)(a) + (ll)(b) ) % (ll)(x)
#define mul_mod(a, b, x) ( ((ll)(a) % (ll)(x)) * ((ll)(b) % (ll)(x)) ) % (ll)(x)

ll sub_mod(ll a, ll b, ll x){
    ll tmp = (a - b) % x;
    if(tmp < 0) tmp += x;
    return tmp;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string a, b, c;
    cin >> a >> b >> c;

    if(stoi(a + b + c) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}