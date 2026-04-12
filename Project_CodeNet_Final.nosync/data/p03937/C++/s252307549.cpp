#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    string ans="Possible";
    for(int i=0;i<h-1;i++){
        for(int j=1;j<w;j++){
            if(a[i][j]=='#'&&a[i+1][j-1]=='#'){
                ans="Impossible";
            }
        }
    }
    cout << ans << endl;
}