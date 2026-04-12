//ABC107B
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;
int main(void){
    int H=0, W=0;
    cin >> H >> W;
    vector<string>L(H, " ");
    rep(i, H) cin >> L[i];
    for(int i=H-1; i>=0; i--){  //行削除は下から
        if(L[i].find('#')==-1){
            L.erase(L.begin()+i);
        }
    }
    vector<int>col(W,0);
    rep(i, L.size()) rep(j, W) if(L[i][j]=='.') col[j]+=1;
    for(int j=W-1; j>=0; j--){ //列削除は右から
        if(col[j]==L.size()){
            for(int i=0; i <L.size(); i++) L[i].erase(L[i].begin()+ j);
        }
    }
    rep(i, L.size()) cout << L[i] << endl;
}