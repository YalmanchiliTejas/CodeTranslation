#include<bits/stdc++.h>
using namespace std;

int main(void){
    int h,w;
    cin >> h >> w;
    char c[h][w];
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> c[i][j];
        }
    }
    bool check = true;
    for(int i = 0,j = 0;i < h && j < w;){
        c[i][j] = '.';
        if(c[i+1][j] == '#')i++;
        else if(c[i][j+1] == '#')j++;
        else {
            break;
        }
    }
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(c[i][j] == '#')check = false;
            //cout << c[i][j];
        }
        //cout << endl;
    }
    if(check == false)cout << "Impossible";
    else cout << "Possible";
}