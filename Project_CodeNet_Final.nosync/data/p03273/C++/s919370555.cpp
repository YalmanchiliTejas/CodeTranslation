#include <iostream>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    string table[h];
    for(int i = 0; i < h; i++){
        cin >> table[i];
    }
    int h_check[h], w_check[w];
    for(int i = 0; i < h; i++){
        h_check[i] = 0;
    }
    for(int i = 0; i < w; i++){
        w_check[i] = 0;
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if( table[i][j] == '#'){
                h_check[i] = 1;
                w_check[j] = 1;
            }
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(h_check[i] == 1 && w_check[j] == 1){
                cout << table[i][j];
            }
        }
        if(h_check[i]){
            cout << endl;
        }
    }
}