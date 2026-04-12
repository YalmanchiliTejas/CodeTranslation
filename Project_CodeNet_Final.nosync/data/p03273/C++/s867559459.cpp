#include <iostream>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string a[100];
    int H, W;
    cin >> H >> W;
    int i = 0;
    int nrow = H;
    while (H--){
        cin >> a[i];
        if (a[i].find("#") == -1){
            nrow--;
        }
        else{
            i++;
        }
    }
    int j = 0;
    while (W--){
        bool is_white = true;
        for (i = 0; i < nrow; i++){
            if (a[i][j] == '#'){
                is_white = false;
            }
        }
        if (is_white) {
            for (i = 0; i < nrow; i++){
                a[i].erase(a[i].begin() + j);
            }
        }
        else{
            j++;
        }
    }
    for (i = 0; i < nrow; i++){
        cout << a[i] << endl;
    }
    return 0;
}
