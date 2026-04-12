#include <bits/stdc++.h>
using namespace std;  

int main(){
    int h, w, sum, row[100] = {}, col[100] = {};
    char a[100][101];
   
    cin >> h >> w;
    for ( int i = 0; i < h; i++ ) {
        cin >> a[i];
    }
    
    for ( int i = 0; i < h; i++ ) {
        sum = 0;
        for ( int j = 0; j < w; j++ ) {
            if ( a[i][j] == '.' ) {
                sum++;
            }
        }
        
        row[i] = sum / w;
    }
    
    for ( int i = 0; i < w; i++ ) {
        sum = 0;
        for ( int j = 0; j < h; j++ ) {
            if ( a[j][i] == '.' ) {
                sum++;
            }
        }
        
        col[i] = sum / h;
    }
    
    for ( int i = 0; i < h; i++ ) {
        for ( int j = 0; j < w; j++ ) {
            if ( row[i] == 0 && col[j] == 0 ) {
                cout << a[i][j];
            }
        }
        if ( row[i] == 0 ) {
            cout << endl;
        }
    }
    
    return (0);
}