#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define MAX 8
int n, m;
int g[MAX][MAX];


bool is_ok(vector<int> &perm) {
    if (perm.at(0) != 0) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        if (!g[perm.at(i - 1)][perm.at(i)]) {
            // if (perm.at(0) == 0 && perm.at(1) == 1) {
            //     cout << "{1, 2, 3}" << endl;
            //     cout << i << endl;
            // }
            return false;
        }
    }
    return true;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    // cout << "g" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm.at(i) = i;
    }
    int ans = 0;
    do {
        // cout << "perm" << endl;
        // for (int p_i : perm) {
        //     cout << p_i << " ";
        // } 
        // cout << endl;
        if (is_ok(perm)) {
            // cout << "perm" << endl;
            // for (int p_i : perm) {
            //     cout << p_i << " ";
            // }    
            // cout << endl;
            ans++;
        }
    } while (next_permutation(begin(perm), end(perm)));
    cout << ans << endl;
}