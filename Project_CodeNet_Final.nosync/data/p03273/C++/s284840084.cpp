#include <iostream>
#include <string>
using namespace std;
bool used_H[100];
bool used_W[100];
int main(void){
    int H,W;
    cin >> H >> W;
    string a[H];
    for(int i=0;i<H;i++){
        cin >> a[i];
    }
    int count = 0;
    for(int i=0;i<H;i++){
        count = 0;
        for(int j=0;j<W;j++){
            if(a[i][j] == '.'){
                count++;
            }
        }
        if(count == W){
            used_H[i] = true;
        }
    }
    for(int i=0;i<W;i++){
        count = 0;
        for(int j=0;j<H;j++){
            if(a[j][i] == '.'){
                count ++;
            }
        }
        if(count == H){
            used_W[i] = true;
        }
    }
    
    for(int i=0;i<H;i++){
        bool OK = false;
        for(int j=0;j<W;j++){
            if(!used_H[i] && !used_W[j]){
                OK = true;
                cout << a[i][j];
            }
        }
        if(OK)cout << endl;
    }
    
}
