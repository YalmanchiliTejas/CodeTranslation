#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define invrep(i,n) for(int i = n; i > 0; i--)

double dist (int i, int j, vector<int> x, vector<int> y) {
    return pow(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2), 0.5);
}

bool g[10][10];
int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> idx;
    rep(i, n1) idx.emplace_back(i);

    int a, b;
    
    rep(i, n2) {
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = true;
    }

    int cnt = 0;
    do {
        if (idx[0] != 0) break;

        bool ok = true;
        rep(i, n1-1) {
            int from = idx[i];
            int to = idx[i+1];
            // cout << from << to << endl;
            if (!g[from][to]) ok = false;
        }

        if (ok) cnt++;
    } while(next_permutation(idx.begin(), idx.end()));
    
    // cout << cnt << endl;
    cout << cnt << endl;
}