#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

inline void equalize(set<pair<int, int> >&a, set<pair<int, int> > &b) {

    while (a.size() > 0 && b.size() > 0 && (*a.rbegin() > *b.begin())) {
        auto largest = a.end();
        largest--;

        b.insert(*largest);
        a.erase(largest);
    }

    while (a.size() > b.size()) {
        auto largest = a.end();
        largest--;

        b.insert(*largest);
        a.erase(largest);
    }

    while (a.size() + 1 < b.size()) {
        auto smallest = b.begin();

        a.insert(*smallest);
        b.erase(smallest);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    set<pair<int, int> > small;
    set<pair<int, int> > large;

    int n;
    cin >> n;

    int X[n];
    vector<pair<int, int> > all;
    for (int i=0; i<n; i++) {
        cin >> X[i];
        all.push_back(make_pair(X[i], i));
    }

    sort(all.begin(), all.end());

    for (int i=0; i<n/2; i++) {
        small.insert({ all[i].first, all[i].second });
    }

    for (int i=n/2; i<n; i++) {
        large.insert({ all[i].first, all[i].second });
    }

    small.erase({ X[0], 0 });
    large.erase({ X[0], 0 });

    equalize(small, large);
    cout << (*large.begin()).first << '\n';

    for (int i=0; i + 1 <n; i++) {
        //insert and print next median
        small.insert({ X[i], i });

        small.erase({ X[i+1], i+1 });
        large.erase({ X[i+1], i+1 });
        equalize(small, large);

        cout << (*large.begin()).first << '\n';
    }

    return 0;
}
