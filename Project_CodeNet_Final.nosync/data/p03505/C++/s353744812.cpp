#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K, A, B;
    cin >> K >> A >> B;
    if (A <= B) {
        if (A >= K) {
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        return 0;
    }
    ll diff = max(K - A, 0LL);
    cout << ((diff + A - B - 1) / (A - B)) * 2 + 1 << endl;
    return 0;
}