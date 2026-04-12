#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> grid(h,vector<char>(w));
    bool allw=true;
    for(int i=0; i<h; i++){
        allw=true;
        for(int j=0; j<w; j++){
            cin>>grid.at(i).at(j);
            if(grid.at(i).at(j)=='#'){
                allw=false;
            }
        }
        if(allw){
            grid.erase(grid.begin()+i);
            i--;
            h--;
        }
    }
    
    allw=true;
    for(int i=0; i<w; i++){
        allw=true;
        for(int j=0; j<h; j++){
            if(grid.at(j).at(i)=='#'){
                allw=false;
            }
        }
        if(allw){
            for(int j=0; j<h; j++){
                grid.at(j).erase(grid.at(j).begin()+i);
            }
            i--;
            w--;
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout<<grid.at(i).at(j);
        }
        cout<<endl;
    }
}
