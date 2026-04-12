#include <bits/stdc++.h>


using namespace std;

int main() {

    
    int col, row, counter = 0, i, j, k, count = 0;
    cin >> row >> col;
    char arr[row][col];
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') counter++;
        }
        if (counter == col) {
            i--;
            row--;
        }
        counter = 0;
    }
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            for (k=0;k<row;k++) {
                if (arr[k][j]=='.') 
                    count++;
            }
            if (count != row) {
                cout << arr[i][j];
            }
            count = 0;
        }
        cout << endl;
    }


    return 0;
}