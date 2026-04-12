#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll h,w;
v2 a;

void no(){
    cout << "Impossible" << endl;
    exit(0);
}

void yes(){
    cout << "Possible" << endl;
    exit(0);
}

int main(){
    cin >> h >> w;
    a = v2(h+2, v1(w+2, 0));
    for(ll i = 1;i <= h;i++){
        for(ll j = 1;j <= w;j++){
            char c;
            cin >> c;
            if(c == '#') a[i][j] = 1;
        }
    }
    ll x,y;
    x = 1;
    y = 1;
    while(true){
        a[x][y] = 0;
        if(a[x+1][y] == 1) x += 1;
        else if(a[x][y+1] == 1) y += 1;
        else break;
    }
    for(ll i = 1;i <= h;i++){
        for(ll j = 1;j <= w;j++){
            if(a[i][j] == 1) no();
        }
    }
    yes();

}
