#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll cy(ll X, ll M) {
    vector<int> check(M, 0);
    ll ans = 0;
    while(check.at(X) == 0) {
        //cout << X << endl;
        check.at(X)++;
        X = (X*X)%M;
    }
    while(check.at(X) == 1) {
        check.at(X)++;
        X = (X*X)%M;
        ans++;
    }

    return ans;
}

ll stx(ll X, ll M) {
    vector<int> check(M, 0);
    ll ans = 0;
    while(check.at(X) == 0) {
        //cout << X << endl;
        check.at(X)++;
        X = (X*X)%M;
    }
    while(check.at(X) == 1) {
        check.at(X)++;
        X = (X*X)%M;
        ans++;
    }

    return X;
}

ll cyzero(ll X, ll M) {
    vector<int> check(M, 0);
    ll ans = 0;
    while(check.at(X) == 0) {
        //cout << X << endl;
        check.at(X)++;
        X = (X*X)%M;
        ans++;
    }

    return ans;
}

bool zeroc(ll N, ll X, ll M) {
    vector<int> check(M, 0);
    ll ans = 0;
    for(int i = 0; i < N && check.at(X) == 0; i++) {
        check.at(X)++;
        X = (X*X)%M;
        ans++;
        if(X == 0) {
            return 1;
        }
    }

    return 0;
}

ll sum(ll N, ll X, ll M) {
    vector<int> check(M, 0);
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        //cout << X << endl;
        ans += X;
        X = (X*X)%M;
    }

    return ans;
}

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    if(zeroc(N, X, M)) {
        cout << sum(M, X, M) << endl;
        return 0;
    }
    ll ans;
    ll rt = cy(X, M);//通常の周期
    ll atama = cyzero(X, M) - rt;//最初何回？
    ll latekai = (N - atama)%rt;//最後何回？
    ll stX = stx(X, M);
    //cout << rt << ':' << atama << ':' << latekai << endl;
    if(rt > N) {
        cout << sum(N, X, M) << endl;
        return 0;
    }
    ans = sum(rt, stX, M)*((N - atama)/rt) + sum(atama, X, M) + sum(latekai, stX, M);

    cout << ans << endl;


    
    

    return 0;
}