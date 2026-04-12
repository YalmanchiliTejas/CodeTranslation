#include <iostream>
#include <string>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    char a[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> a[i][j];
        }
    }        

    bool canH[H];
    for(int i=0; i<H; i++){
        bool can = false;
        for(int j=0; j<W; j++){
            if(a[i][j] == '#'){
                can = true;
            }
        }
        // cout << can;
        canH[i] = can;
    }

    // cout << endl << endl;

    bool canW[W];
    for(int i=0; i<W; i++){
        bool can = false;
        for(int j=0; j<H; j++){
            if(a[j][i] == '#'){
                can = true;
            }
        }
        // cout << can;
        canW[i] = can;
    }

    // cout << endl << endl;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(canH[i] && canW[j]){
                cout << a[i][j];
            }
        }
        if(canH[i]) cout << endl;  
    }
}
