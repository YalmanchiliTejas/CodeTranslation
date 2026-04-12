#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    char A[h][w];
    int sharp=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> A[i][j];
            if(A[i][j]=='#')
                sharp++;
        }
    }
    if(sharp == h + w -1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;

}