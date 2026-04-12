#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> len;
vector<ll> np;

ll solve(ll n, ll x){
    if(n == 0){
        return (ll)(x > 0);
    }else if(x < len.at(n - 1) + 2){
        return solve(n - 1, x - 1);
    }else{ // x < len.at(n) - 1
        return np.at(n - 1) + 1 +
            solve(n - 1, x - len.at(n - 1) - 2);
    }
}

int main(){
    ll n, x;
    cin >> n >> x;

    len.resize(n + 1, 0);
    np.resize(n + 1, 0);
    len.at(0) = 1;
    np.at(0) = 1;
    for(int i = 1; i <= n; ++i){
        len.at(i) = 2 * len.at(i - 1) + 3;
        np.at(i) = 2 * np.at(i - 1) + 1;
    }

    cout << solve(n, x) << endl;
    return 0;
}
