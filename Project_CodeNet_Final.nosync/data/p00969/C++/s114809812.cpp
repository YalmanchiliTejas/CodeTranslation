#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> a;
map<int,int> ma;

int dp[5100][5100] = {0};
int rec(int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    int val = a[i] * 2 - a[j];
    if (!ma.count(val)) return 2;
    int k = ma[val];
    int res = rec(k, i) + 1;
    
    //cout << i << ", " << j << ": " << res << endl;
    
    return dp[i][j] = res;
}

int main() {
    int N; cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    
    for (int i = 0; i < N; ++i) ma[a[i]] = i;
    int res = 2;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            res = max(res, rec(i, j));
        }
    }
    cout << res << endl;
}
