#include <iostream>
using namespace std;
typedef long long int lint;
int main(void){
    lint H,W;
    cin >> H >> W;
    string* a = new string[H];
    for(lint i = 0;i < H;i++)
        cin >> a[i];
    string tmp1 = "";
    for(lint i = 0;i < W;i++)
        tmp1 += ".";
    bool* blank = new bool[W];
    for(lint j = 0;j < W;j++)
        blank[j] = false;
    string* b = new string[H];
    for(lint i = 0;i < H;i++){ //yoko
        if(a[i] != tmp1){
            b[i] = a[i];
            
        }
    }
    for(lint j = 0;j < W;j++){ //tate
        for(lint k = 0;k < H;k++){
            if(b[k][j] == '#'){
                blank[j] = true;
                break;
            }
        }
    }
    for(lint i = 0;i < H;i++){ //hyoji
        if(b[i] != "\0"){
            for(lint j = 0;j < W;j++){
                if(blank[j])
                    cout << b[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}