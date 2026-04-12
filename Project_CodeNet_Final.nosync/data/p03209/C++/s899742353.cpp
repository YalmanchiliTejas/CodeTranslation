#include <bits/stdc++.h>
using namespace std;

long long n, x, k, p;
pair<long long, long long> a[52];
vector<pair<long long, long long> > v[52];

void bg(long long dg) {
    for(int i = 0; i < v[dg].size(); ++i) {
        if(v[dg][i].second == 2) {
            if(k >= v[dg][i].first) {
                k -= v[dg][i].first;
                p += a[dg - 1].first;
            } else {
                bg(dg - 1);
            }
        } else {
            if(k) {
                --k;
                if(v[dg][i].second == 0) {
                    ++p;
                }
            } else {
                cout << p << endl;
                exit(0);
            }
        }
    }
}

int main() {
    cin >> n >> x;
    k = x;
    v[0].push_back({1, 0});
    a[0].first = 1;
    for(int i = 1; i <= n; ++i) {
        v[i].push_back({1, 1});
        v[i].push_back({a[i - 1].first + a[i - 1].second, 2});
        v[i].push_back({1, 0});
        v[i].push_back({a[i - 1].first + a[i - 1].second, 2});
        v[i].push_back({1, 1});
        a[i].first = 2 * a[i - 1].first + 1;
        a[i].second = 2 * a[i - 1].second + 2;
    }
    bg(n);
    cout << p << endl;
}