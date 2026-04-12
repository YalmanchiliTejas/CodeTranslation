#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    bool lb = false;
    int n;
    while (cin >> n, n) {
        vector<pair<int,pair<int,string>>> v(n);
        string name;
        int win, lose, draw;
        for (int i=0; i<n; ++i) {
            cin >> name >> win >> lose >> draw;
            v[i] = make_pair(-win*3-draw, make_pair(i, name));
        }
        sort(v.begin(), v.end());
        if (lb) {
            cout << endl;
        } else {
            lb = true;
        }
        for (int i=0; i<n; ++i) {
            cout << v[i].second.second << "," << -v[i].first << endl;
        }
    }
    return 0;
}