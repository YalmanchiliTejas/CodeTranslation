#include <bits/stdc++.h>
using namespace std;



int main(){
    int H,W;
    cin>>H>>W;
    vector<string> grid(H);
    for(int i=0; i<H; i++){
        cin>>grid.at(i);
    }
    vector<bool> tate(H,false);
    vector<bool> yoko(W,false);
    for(int j=0; j<H; j++){
        for(int k=0; k<W; k++){
            if((grid.at(j)).at(k) == '#'){
                tate.at(j) = true;
                yoko.at(k) = true;
            }
        }    
    }
    for(int i=0; i<H; i++){
        if(tate.at(i)){
            for(int j=0; j<W; j++){
                if(yoko.at(j)){
                    cout<<grid.at(i).at(j);
                }
            }
            cout<<endl;
        }
    }
}
