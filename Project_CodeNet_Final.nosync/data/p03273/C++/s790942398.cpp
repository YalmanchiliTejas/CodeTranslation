#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, i, j, k;
    cin >> h >> w;
    char a[h][w+1];
    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            cin >> a[i][j];
        }
    }
    for(i=0; i<h; i++){
        a[i][w] = '\n';
    }
    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            if(a[i][j] == '#'){
                break;
            }
            if(j == w-1){
                for(k=0; k<=w; k++){
                    a[i][k] = ' ';
                }
            }
        }
    }
    for(j=0; j<w; j++){
        for(i=0; i<h; i++){
            if(a[i][j] == '#'){
                break;
            }
            if(i == h-1){
                for(k=0; k<h; k++){
                    a[k][j] = ' ';
                }
            }
        }
    }
    for(i=0; i<h; i++){
        for(j=0; j<=w; j++){
            if(a[i][j] != ' '){
                cout << a[i][j];
            }
        }
    }
    return 0;
}