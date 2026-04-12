#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    multiset<ll> s;

    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // auto idx = s.lower_bound(1);
    // cout << *s.begin() << endl;
    // cout << *idx << endl;

    // return 0;
    rep(i, N) {
        if (s.size() == 0) {
            s.insert(A[i]);
            continue;
        }

        // 最初の要素より小さい場合
        if (A[i] <= *s.begin()) {
            // cout << "i1: " << i << endl; 
            s.insert(A[i]);
        } else if (A[i] > *s.rbegin()) {
            // cout << "i2: " << i << " " << *s.rbegin() << endl; 

            // 最後の要素より大きい
            s.erase(s.find(*s.rbegin()));
            s.insert(A[i]);
        } else {
            auto idx = prev(s.lower_bound(A[i]));

            // cout << "i3: " << i << " " << *idx << endl; 
            s.erase(s.find(*idx));
            s.insert(A[i]);
        } 

        // // debug
        // cout << " ";
        // for (auto v : s) {
        //     cout << v << " ";
        // }
        // cout << endl;
    }


    cout << s.size() << endl;
}