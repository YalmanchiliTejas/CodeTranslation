#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjmat(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjmat.at(a - 1).at(b - 1) = 1;
        adjmat.at(b - 1).at(a - 1) = 1;
    }
    
    vector<int> a;
    for (int i = 0; i < n ; i++) {
        a.push_back(i);
    }
    int cnt = 0;
    do {
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (adjmat.at(a.at(i)).at(a.at(i + 1)) == 0) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        cnt++;
    } while (next_permutation(a.begin(), a.end()) && a.at(0) == 0);
    
    cout << cnt << endl;
    
    return 0;
}
