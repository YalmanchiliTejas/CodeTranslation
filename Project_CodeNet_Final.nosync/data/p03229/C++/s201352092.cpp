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

    vector<ll> A(N);
    Rep (i, N) cin >> A.at(i);

    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0;
    if (N % 2) {
        vector<ll> w;
        Rep (i, N/2) w.push_back(2);
        Rep (i, 2) w.push_back(-1);
        Rep (i, N/2-1) w.push_back(-2);
        // for (auto e : w) cout << e << " ";
        // cout << "\n";
        ll sub = 0;
        Rep (i, N) sub += A[i] * w[i];
        Rep (i, N) w[i] *= -1;
        sort(w.begin(), w.end(), greater<ll>());
        Rep (i, N) ans += A[i] * w[i];
        // cout << ans << " " << sub << "\n";
        ans = max(ans, sub);
    } else {
        Rep (i, N) {
            if (i < N/2-1) ans += 2*A[i];
            else if (i < N/2) ans += A[i];
            else if (i < N/2+1) ans -= A[i];
            else ans -= 2*A[i]; 
        }
    }
    cout << ans << "\n";
}