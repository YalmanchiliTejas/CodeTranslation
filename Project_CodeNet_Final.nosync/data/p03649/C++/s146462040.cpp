#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    ll sum = 0;
    for (auto& a : A) {
        sum += a / N;
    }
    ll ans = 0;
    while (sum > 0) {
        ans += sum;
        for (auto& a : A) {
            a -= (a / N) * N - sum + a / N;
        }
        sum = 0;
        for (auto& a : A) {
            sum += a / N;
        }
    }
    cout << ans << endl;
    return 0;
}