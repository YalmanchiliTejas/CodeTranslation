#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    string a[H];
    bool check_x[W] = {},check_y[H] = {};
    for(int i=0;i<H;i++){
        cin >> a[i];
    }    
    int cnt;
    for(int i=0;i<H;i++){
        cnt = 0;
        for(int j=0;j<W;j++){
            if(a[i][j] == '.'){
                cnt++;
            }
        }
        if(cnt == W){
            check_x[i] = true;
        }
    }
    for(int j=0;j<W;j++){
        cnt = 0;
        for(int i=0;i<H;i++){
            if(a[i][j] == '.'){
                cnt++;
            }
        }
        if(cnt == H){
            check_y[j] = true;
        }
    }

    for(int i=0;i<H;i++){
        if(check_x[i]){
            continue;
        }
        for(int j=0;j<W;j++){
            if(check_y[j]){
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
}
