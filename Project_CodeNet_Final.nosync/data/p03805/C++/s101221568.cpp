#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>

using namespace std;

int main() {
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool path[n][n];
    fill(path[0], path[n], false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        path[a-1][b-1] = true;
        path[b-1][a-1] = true;
    }
    
    int perm[n-1];
    iota(perm, perm+n-1, 1);
    
    unordered_set<int> ok;
    int pattern = 0;
    do
    {
        ok.clear();
        ok.insert(0);
        
        int prev = 0;
        for(int x : perm) {
            if(path[prev][x]) {
                ok.insert(x);
                prev = x;
            } else {
                break;
            }
        }
        
        if(ok.size() == (size_t)n) {
            pattern++;
        }
    }while(next_permutation(perm, perm+n-1));
    
    cout << pattern << endl;
    
}