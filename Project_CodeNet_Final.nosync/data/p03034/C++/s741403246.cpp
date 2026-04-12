#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> s(N);
    Rep (i, N) {
        cin >> s[i];
    }

    ll ans = 0;
    set<ll> passed;
    for (ll C = 1; C < N; C++) {
        ll score = 0;
        passed.clear();
        for (ll n = 0; N-1-n*C > 0; n++) {
            ll A = N-1 - n*C;
            ll B = A - C;
            // cout << "C, n, A, B: " << C << " " << n << " " << A << " " << B << "\n";
            score += s[n*C] + s[N-1-n*C];
            if (A <= 0 || B <= 0 || A <= B) continue;
            if (passed.count(n*C) || passed.count(N-1-n*C) || n*C == N-1-n*C) continue;
            passed.insert(n*C);
            passed.insert(N-1-n*C);
            ans = max(ans, score);

            // cout << A << " " << B << " " << score << "\n";
        }
    }

    cout << ans << endl;
}