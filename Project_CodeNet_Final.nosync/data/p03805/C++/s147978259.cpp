#include <iostream>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, m, a, b;
    bool brg[8][8];
    cin >> n >> m;
    for (int i = 0; i < n*n; i++) brg[i/n][i%n] = false;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        brg[a-1][b-1] = true;
        brg[b-1][a-1] = true;
    }
    
    int ans = 0;
    for (int i = 0; i < pow(n - 1, n - 1); i++) {
        int il[8], ic = i;
        il[0] = 0;
        for (int j = 0; j < n - 1; j++) {
            il[j + 1] = ic % (n - 1) + 1;
            ic /= n - 1;
        }
        bool check = true;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (il[j] == il[k]) check = false;
            }
        }
        if (check) {
            for (int j = 0; j < n - 1; j++) {
                if (!brg[il[j]][il[j + 1]]) break;
                if (j == n - 2) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << endl;
}
