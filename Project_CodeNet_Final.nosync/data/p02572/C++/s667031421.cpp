#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;


int main() {
    ll N, sum = 0, ans = 0;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    for (int i = 0; i < N; i++){
        sum -= A.at(i);
        ans += (sum % 1000000007) * A.at(i);
        ans %= 1000000007;
    }
    cout << ans << endl;
}