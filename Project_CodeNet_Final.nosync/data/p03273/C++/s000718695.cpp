#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w; cin>>h>>w;
    vector<string> grid(h);
    for(int i=0; i<h; i++) cin>>grid.at(i);
    vector<bool> blackH(h,false);
    vector<bool> blackW(w,false);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(grid.at(i).at(j) == '#'){
                blackH.at(i) = true;
                blackW.at(j) = true;
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(blackH.at(i) and blackW.at(j))
                cout<<grid.at(i).at(j);
        }
        cout<<'\n';
    }
}
