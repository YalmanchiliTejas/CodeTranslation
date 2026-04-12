#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> patty(51);
    patty[0] = 1;

    vector<ll> burger(51);
    burger[0] = 1;

    for(int i = 1; i <= 50; i++){
        patty[i] = patty[i - 1] * 2 + 1;
        burger[i] = burger[i - 1] * 2 + 3;
    }

    function<ll(int, ll)> f = [&](int ni, ll xi) -> ll{
        if(ni == 0 && xi >= 1){
            return 1;
        }

        if(xi <= 1){
            return 0;
        }else if(xi <= burger[ni - 1] + 1){
            return f(ni - 1, xi - 1);
        }else if(xi == burger[ni - 1] + 2){
            return patty[ni - 1] + 1;
        }else{
            return patty[ni - 1] + 1 + f(ni - 1, xi - 2 - burger[ni - 1]);
        }
    };

    cout << f(n, x) << endl;
    return 0;
}
