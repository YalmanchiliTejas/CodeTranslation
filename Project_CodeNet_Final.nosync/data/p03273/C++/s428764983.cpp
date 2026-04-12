#include<bits/stdc++.h>
using namespace std;

int main(void){
    char c[100][100];
    int a[100][100] = {};
    int h,w;
    cin >> h >> w;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++)cin >> c[i][j];
    }
    
    for(int i = 0;i < h;i++){
        bool check = true;
        for(int j = 0;j < w;j++){
            if(c[i][j] == '#')check = false;
        }
        if(check == true){
            for(int j = 0;j < w;j++)a[i][j] = 1;
        }
    }
    
    for(int i = 0;i < w;i++){
        bool check = true;
        for(int j = 0;j < h;j++){
            if(c[j][i] == '#')check = false;
        }
        if(check == true){
            for(int j = 0;j < h;j++)a[j][i] = 2;
        }
    }
    for(int i = 0;i < h;i++){
        if(a[i][0] == 1)continue;
        for(int j = 0;j < w;j++){
            if(a[i][j] == 0)cout << c[i][j];
        }
        cout << endl;
    }
}