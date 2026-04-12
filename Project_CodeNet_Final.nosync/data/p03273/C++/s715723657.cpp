#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int h,w;
    cin >> h >> w;
    vector<string> b(h);
    for(int i=0;i<h;i++){
        int ok=0;
        cin >> b[i];
        for(int j=0;j<w;j++){
            if(b[i][j]=='#'){
                ok=1;
            }
        }
        if(ok==0){
            i--;
            h--;
        }
    }
    for(int i=0;i<w;i++){
        int ok=0;
        for(int j=0;j<h;j++){
            if(b[j][i]=='#'){
                ok=1;
            }
        }
        if(ok==0){
            for(int j=0;j<h;j++){
                b[j].erase(i,1);
            }
            i--;
            w--;
        }
    }
    for(int i=0;i<h;i++){
        cout << b[i] << endl;
    }
}
