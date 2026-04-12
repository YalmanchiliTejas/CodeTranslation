#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main () {
    vector<ii> ts;
    int id, solve;
    while (scanf("%d,%d", &id, &solve), id|solve) {
        ts.push_back(make_pair(solve, id));
    }
    sort(ts.begin(), ts.end(), greater<ii>());
    map<int, int> rs;
    int rank = 0;
    int pre = -1;
    for (vector<pair<int, int> >::iterator it = ts.begin(); it != ts.end(); it++) {
        if (it->first == pre) {
            rs[it->second] = rank;
        } else {
            rs[it->second] = ++rank;
            pre = it->first;
        }
    }
    while (cin >> id) {
        cout << rs[id] << endl;
    }
}