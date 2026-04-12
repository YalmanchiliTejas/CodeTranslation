#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    ll a, b, c, x, y;
    ll ans = inf;
    cin >> a >> b >> c >> x >> y;
    for(int i = 0;i <= 2 * max(x, y);i++){
        ll sum = 0;
        if(x - i/2 <= 0 && y - i / 2 <= 0){
            sum = i * c;
        }
        else if (x - i/2 <= 0 && y - i / 2 > 0)
        {
            sum = i*c + b * (y - i / 2);
        }
        else if(x - i/2 > 0 && y - i / 2 <= 0){
            sum = i * c + a * (x - i / 2);
        }
        else{
        sum = i * c + a * (x - i / 2) + b * (y - i / 2);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}