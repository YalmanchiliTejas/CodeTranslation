#include <bits/stdc++.h>

using namespace std;
int main(){
    int H,W;
    cin >> H >> W;
    char a[100][100];
    for(int i = 0; i < H; i++){
        for(int j = 0;j < W; j++){
            cin >> a[i][j];
        }    
    }
    vector<int> b;
    int k = 0;
    for(int i = 0; i < W; i++){
        while(a[k][i] == '.'){
            k++;
        }
        if(k < H){
            b.push_back(i);
        }
        k = 0;
    }
    for(int i = 0; i < H; i++){
        while(a[i][k] == '.'){
            k++;
        }
        if(k < W){
            for(int j = 0; j < b.size(); j++){
                cout << a[i][b[j]];
            } 
            cout << endl;
        }
        k = 0;
    }
}