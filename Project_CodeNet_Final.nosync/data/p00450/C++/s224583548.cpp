#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n and n) {
        vector<int> counter, color;
        for(int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            if(i % 2) {
                if(color.empty() or color.back() != c) {
                    counter.push_back(1);
                    color.push_back(c);
                } else {
                    counter.back()++;
                }             
            } else {
                if(color.back() == c) {
                    counter.back()++;
                } else {
                    int x = counter.back();
                    counter.pop_back();
                    color.pop_back();
                    if(counter.empty()) {
                        counter.push_back(x + 1);
                        color.push_back(c);
                    } else {
                        counter.back() += x + 1;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < color.size(); i++) {
            if(not color[i]) {
                ans += counter[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

