#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;
    for(int i = 0; i <= X; i++){
        ll price = i * A;
        price += (X - i) * C * 2;
        if(Y - X + i >= 0){
            ll price2 = price + B * (Y - X + i);
            ll price3 = price + C * 2 * (Y - X + i);
            // cout << i << " " << price2 << " " << price3 << endl; 
            ans = min(ans, price2);
            ans = min(ans, price3);
        }else ans = min(ans, price);
        
    }
    cout << ans << endl;
}