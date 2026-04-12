#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }

    bool flagW = true;
    for(int i=0;i<W;i++){
        flagW= true;
        for(int j=0;j<H;j++){
            if(a[j][i]=='#'){
                flagW = false;
                break;
            }
        }
        if(flagW){
            for(int k=0;k<H;k++){
                a[k][i] = '0';
            }
        }
    }

    bool flagH = true;
    for(int i=0;i<H;i++){
        flagH = true;
        for(int j=0;j<W;j++){
            if(a[i][j]=='#'){
                flagH = false;
                break;
            }
        }
        if(flagH){
            for(int k=0;k<W;k++){
                a[i][k] = '1';
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='0'){
                if(j==W-1){
                    cout << endl;
                }
                continue;
            }else if(a[i][j]=='1'){
                    continue;
            }else{
                cout << a[i][j];
                if(j==W-1){
                    cout << endl;
                }
            }
        }
    }
}
