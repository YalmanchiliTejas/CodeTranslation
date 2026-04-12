#include <iostream>
using namespace std;
int h, w;
char a[101][101];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        bool brise = true;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                brise = false;
            }
        }

        if(brise == true){
            for(int j = 0; j < w; j++){
                a[i][j] = '!';
            }
        }
    }
    for(int i = 0; i < w; i++){
        bool brise = true;
        for(int j = 0; j < h; j++){
            if(a[j][i] == '#'){
                brise = false;
            }
        }

        if(brise == true){
            for(int j = 0; j < h; j++){
                a[j][i] = '!';
            }
        }
    }
     for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] != '!'){
                cout << a[i][j];
            }
        }cout << "\n";
    }
}