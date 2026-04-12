#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>
using namespace std;

double inf = numeric_limits<double>::infinity();

int main() {
    int n, m;
    
    cin >> n >> m;
    vector<vector<int>> v = vector<vector<int>>(n, vector<int>(n, 0));
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }
    
    vector<int> vlist;
    for (int i = 0; i < n; i++) {
        vlist.push_back(i);
    }
    
    int cnt = 0;
    do {
        if (vlist[0] == 0) {
            bool t = true;
            for (int i = 1; i < n; i++) {
                t = t && v[vlist[i-1]][vlist[i]] == 1;
            }
            if (t) cnt++;
        }
    } while (next_permutation(vlist.begin(), vlist.end()));
    
    cout << cnt << endl;
}