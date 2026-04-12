#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i,H){
        cin >> a[i];
    }
    vector<bool> row(H, false);
    vector<bool> cul(W, false);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j]=='#'){
                row[i] = true;
                cul[j] = true;
            }
        }
    }
    for (int  i = 0; i < H; i++)
    {
        if(row[i]){
            for (int  j = 0; j < W; j++)
            {
                if(cul[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    
}