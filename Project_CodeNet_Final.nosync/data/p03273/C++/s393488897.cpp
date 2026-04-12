#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
char a[101][101];
bool flag [101];
bool flag2[101];
int main() {
    memset(flag, false, 101);
    memset(flag2,false, 101);
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= W; i++) {
        if (a[1][i] == '.') {
            int k ;
            for (k = 1; k <= H; k++) {
                if (a[k][i] != '.') { 
                    break;
                }
            }
            if (k > H) {
                flag[i] = true;
            }
        }
    } 
    for (int i = 1; i <= H; i++) {
        if (a[i][1] == '.') {
            int k ;
            for (k = 1; k <= W; k++) {
                if (a[i][k] != '.') { 
                    break;
                }
            }
            if (k > W) {
                flag2[i] = true;
            }
        }
    } 
    for (int i = 1; i <= H; i++) {
        if (flag2[i] == false) {
            for (int j = 1; j <= W; j++) {
                if (flag[j] == false) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }     

    return 0;
}
