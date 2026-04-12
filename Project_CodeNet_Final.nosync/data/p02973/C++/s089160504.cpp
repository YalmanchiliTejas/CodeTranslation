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
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    int ans = 0;
    vector<int> colored;
    for (auto& a : A) {
        auto itr = lower_bound(colored.rbegin(), colored.rend(), a);
        if (itr == colored.rbegin()) {
            colored.push_back(a);
            ++ans;
        } else {
            auto prev_itr = itr.base();
            *prev_itr = a;
        }
    }
    cout << ans << endl;
    return 0;
}