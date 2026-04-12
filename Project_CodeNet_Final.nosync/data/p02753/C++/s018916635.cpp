#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
#define PUTS(x) cout << (x) << endl;
#define PB push_back
#define MP make_pair
#define F first
#define S second
vector<Int> IntsIn(int n) {
    auto v = vector<Int>(0);
    for (int i = 0; i < n; i++) {
        Int a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    auto s = set<char>();
    s.insert(a);
    s.insert(b);
    s.insert(c);
    puts(s.size() == 1 ? "No" : "Yes");
}