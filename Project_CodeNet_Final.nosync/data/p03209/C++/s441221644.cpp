#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

vector<ll> layers(51,-1);
vector<ll> pt(51,-1);

pair<ll, ll> calc(ll level, ll x){
    ll pre_x = x;
    if(x == 0) return make_pair(0,0);
    if(level == 0){
        return make_pair(1, 1);
    }

    ll ans = 0;
    if(layers[level] != -1 && layers[level] <= x){
        ans = pt[level];
        x -= layers[level];
    } else {
        x--;
        auto tmp = calc(level-1, x);
        ans += tmp.first;
        x -= tmp.second;
        if(x > 0){
            ans++;
            x--;
            if(x > 0){
                tmp = calc(level-1, x);
                ans += tmp.first;
                x -= tmp.second;
                if(x > 0 && layers[level] == -1){
                    layers[level] = pre_x-x+1;
                    pt[level] = ans;
                }
                if(x > 0) x--;
            }
        }
    }

   // cout << "layer:" << level << " num:" << pre_x-x << " pt:" << ans << endl;

    return make_pair(ans, pre_x-x);
}

int main(){
    ll n,x;
    cin >> n >> x;

    auto ans = calc(n,x);
    cout << ans.first << endl;
    
    return 0;
}