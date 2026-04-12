#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> team(101, 0), rank(31, 0), tmp;
    int num, solved;
    char c;
    while (cin >> num >> c >> solved, num) {
        team[num] = solved;
        tmp.push_back(solved);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    sort(tmp.begin(), tmp.end(), greater<int>());
    for (int i=0; i<(int)tmp.size(); ++i) {
        rank[tmp[i]] = i+1;
    }
    int n;
    while (cin >> n) {
        cout << rank[team[n]] << endl;
    }
    return 0;
}