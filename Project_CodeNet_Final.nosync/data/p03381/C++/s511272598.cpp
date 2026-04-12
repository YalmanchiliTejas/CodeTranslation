#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

const int MAXN = 200000;

int a[MAXN + 1], b[MAXN + 1];

void add(int x, multiset<int> &s1, multiset<int> &s2) {
    s2.insert(x);
    while (s1.size() < s2.size() - 1) {
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
}

void del(int x, multiset<int> &s1, multiset<int> &s2) {
    if (s2.find(x) != s2.end()) {
        s2.erase(s2.find(x));
    } else {
        s1.erase(s1.find(x));
    }
    while (s1.size() > s2.size()) {
        auto it = s1.end();
        --it;
        s2.insert(*it);
        s1.erase(it);
    }
    while (s1.size() + 1 < s2.size()) {
        auto it = s2.begin();
        s1.insert(*it);
        s2.erase(it);
    }
}

int get(multiset<int> &s1, multiset<int> &s2) {
    return *s2.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);

    int n;
    cin >> n;
    multiset<int> s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        add(a[i], s1, s2);
    }
    for (int i = 0; i < n; i++) {
        del(b[i], s1, s2);
        cout << get(s1, s2) << "\n";
        add(b[i], s1, s2);
    }
    return 0;
}