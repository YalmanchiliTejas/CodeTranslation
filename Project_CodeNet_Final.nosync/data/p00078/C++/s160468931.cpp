#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int field[n][n];
        for(int i=0; i < n; i++)for(int j=0; j< n; j++) field[i][j] = 0;
        int x = n/2+1, y = n/2;
        field[x][y] = 1;
        for(int i=2; i <= n*n; i++){
            x++; y++;
            if(!(0 <= x && x < n)) x = 0;
            if(!(0 <= y && y < n)) y = 0;
            if(field[x][y] != 0){
                x++; y--;
                if(!(0 <= x && x < n)) x = 0;
                if(!(0 <= y && y < n)) y = n-1;
            }
            field[x][y] = i;
        }
        for(int i=0; i< n; i++){
            for(int j=0; j < n; j++){
                printf("% 4d", field[i][j]);
            }
            cout << endl;
        }
    }
}