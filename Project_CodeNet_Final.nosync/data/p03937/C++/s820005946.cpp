#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W; cin >> H >> W;
    char a[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    bool check=true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if((i+1)<H&&(j-1)>=0){
                if(a[i+1][j-1]=='#'&&a[i][j]=='#') check=false;
            }
        }
    }
    if(check) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
}