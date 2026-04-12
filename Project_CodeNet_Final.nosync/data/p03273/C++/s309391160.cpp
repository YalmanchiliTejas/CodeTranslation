#include <iostream>
using namespace std;
int main (){
    int h,w;
    cin >> h >> w;
    int state[h][w];
    char tmp;
    for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
        cin >> tmp;
        if(tmp == '#') state[i][j] = 1;
        else state[i][j] = 0 ;
    }
    }
    int row[h]={};
    int col[w]={};
    cout<<"\n";
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            row[i]+=state[i][j];
            col[j]+=state[i][j];
//            cout << state[i][j];
        }
//    cout << "\n";
    }

    for (int i = 0; i < h; i++){
        if(row[i]){
            for (int j = 0; j < w; j++){
            if(col[j]){
                if(state[i][j]) cout << "#";
                else cout << ".";
            }
        }
        cout << "\n";
        }
    }
}