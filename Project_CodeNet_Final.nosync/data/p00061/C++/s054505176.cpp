#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    vector<pii> v;
    int p, s;
    while (scanf("%d,%d", &p, &s), p) {
        v.push_back(pii(s, p));
    }

    int rank[150], r = 1;
    sort(v.begin(), v.end(), greater<pii>());
    rank[v[0].second] = r;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first != v[i - 1].first) r++;
        rank[v[i].second] = r;
    }

    int q;
    while (scanf("%d", &q) != EOF)
        cout << rank[q] << endl;

    return 0;
}
