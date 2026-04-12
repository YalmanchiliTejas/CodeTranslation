#include <iostream>

using namespace std;

int h, w; //縦,横
string mat[100];
bool a[100], b[100];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> mat[i];
    }
    for(int i = 0; i < h; i++){
        bool flag = true;
        for (int j = 0; j < w; j++) {
            if(mat[i][j]=='#'){
                flag = false; 
            }
        }
        a[i] = flag;
    }
    for(int j = 0; j < w; j++){
        bool flag = true;
        for (int i = 0; i < h; i++) {
            if(mat[i][j]=='#'){
                flag = false;
            }
        }
        b[j] = flag;
    }
    for (int i = 0; i < h; i++) {
        if(a[i]){
            continue;
        }
        for (int j = 0; j < w; j++) {
            if(!b[j]){
                cout << mat[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
