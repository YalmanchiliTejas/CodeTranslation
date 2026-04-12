#include <iostream>
#include <stdio.h>

#include <string>
 
using namespace std;
 
int main(void) {
    int h, w;
    cin >> h >> w;
    string str[h];
    string check(w, '.');
    int line = 0;
    for(int i = 0; i < h; i++){
        cin >> str[line];
        if(str[line] != check){
            line++;
        }
    }
    int out[w] = {};
    for(int i = 0; i < w; i++){
        if(str[0][i] == '.'){
            int a = 0;
            for(int j = 0; j < line; j++){
                if(str[j][i] == '#'){
                    a++;
                    break;
                }
            }
            if(a == 0){
                out[i] = 1;
            }
        }
    }
    for(int i = 0; i < line; i++){
        for(int j = 0; j < w; j++){
            if(out[j] == 0){
                cout << str[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}