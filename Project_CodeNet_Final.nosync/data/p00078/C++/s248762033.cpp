#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        int ma[n + 1][n + 1]; //1index
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ma[i][j] = 0;
            }
        }
        int tate = n/2 + 2, yoko = n/2 + 1;
        int cnt = 1;
        ma[tate][yoko] = cnt;
        tate += 1; yoko += 1;
        while (1) {
            if (1 <= tate && tate <= n && 1 <= yoko && yoko <= n) {
                if (ma[tate][yoko] == 0) {
                    ma[tate][yoko] = ++cnt;
                    tate++; yoko++;
                    if (cnt == pow(n, 2) ) {
                        break;
                    }
                } else {
                    tate++; yoko--;
                }
            } else if (yoko > n){ //over right 最初はあり得ない
                yoko = 1;
            } else if (tate > n) { //over bottom
                tate = 1;
            } else if (yoko < 1){ //over left
                yoko = n;
            }
            /*
            cout << tate << " " << yoko << endl;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << ma[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            */
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%4d", ma[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}

