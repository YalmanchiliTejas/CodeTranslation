#include<bits/stdc++.h>
using namespace std;

int main(void){
    int h,w;
    cin >> h >> w;

    char array[h][w];

    int i,j;
    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            cin >> array[i][j];
        }
    }

    int flag;
    for(i=0; i<h; i++){
        flag = 1;
        for(j=0; j<w; j++){
            if(array[i][j] == '#'){
                flag = 0;
            }
        }
        if(flag == 1){
            for(j=0; j<w; j++){
                array[i][j] = '*';
            }
        }
    }

    for(i=0; i<w; i++){
        flag = 1;
        for(j=0; j<h; j++){
            if(array[j][i] == '#'){
                flag = 0;
            }
        }
        if(flag == 1){
            for(j=0; j<h; j++){
                array[j][i] = '*';
            }
        }
    }

    for(i=0; i<h; i++){
        flag = 0;
        for(j=0; j<w; j++){
            if(array[i][j] != '*'){
                cout << array[i][j];
                flag = 1;
            }
        }
        if(flag == 1){
            cout << endl;
        }
    }


    return 0;
}