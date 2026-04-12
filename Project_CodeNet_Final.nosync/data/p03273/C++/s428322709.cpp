#include <iostream>
using namespace std;

bool is[110];
bool js[110];

int main(){
    int h, w;
    char a[110][110];
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < h; i++){
        bool omit = true;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                omit = false;
                break;
            }
        }
        if(!omit){
            is[i] = true;
        }
    }
    for(int j = 0; j < w; j++){
        bool omit = true;
        for(int i = 0; i < h; i++){
            if(a[i][j] == '#'){
                omit = false;
                break;
            }
        }
        if(!omit){
            js[j] = true;
        }
    }
    
    
    for(int i = 0; i < h; i++){
        if(!is[i]){
            continue;
        }
        for(int j = 0; j < w; j++){
            if(!js[j]){
                continue;
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
}