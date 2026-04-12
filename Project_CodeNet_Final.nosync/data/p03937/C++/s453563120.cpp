#include <stdio.h>
#include <iostream>
using namespace std;

char a[100][100];
int main()
{
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    a[1][1] = '.';
    int flag  = 1;
    int i = 1;
    int j = 1;
    while(j <= w) {
        int ok = 0;
        if(a[i][j + 1] == '#') {  // 可向右
            a[i][j + 1] = '.';
            ok = 1;
            j++;
        } else {
            if(a[i + 1][j] == '#') {// 可以向下
                a[i + 1][j] = '.';
                i++;
                ok = 1;
            }
        }
        if(ok == 0){
            flag = 0;
            break;
        }

        if(i == h && j == w){
            break;
        }

    }
    for(i = 1; i <= h; i++) {
        for(j = 1; j <= w; j++) {
            if(a[i][j] == '#') {
                flag = 0;
                break;
            }
        }
        if(flag == 0) {
            break;
        }

    }
    if(flag) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
