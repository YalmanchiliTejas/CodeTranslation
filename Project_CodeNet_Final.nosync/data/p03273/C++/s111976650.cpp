#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int H,W;
    
    cin >> H >> W;
    
    vector<string> tbl(H);
    
    for(int i = 0; i < H; i++){
        cin >> tbl.at(i);
    }
    
    vector<bool> col(W,false);
    vector<bool> row(H,false);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(tbl.at(i).at(j) == '#'){
                col.at(j) = true;
                row.at(i) = true;
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        if(row.at(i)){
           for(int j = 0; j < W; j++){
               if(col.at(j)){
                   cout << tbl.at(i).at(j);
               }
                
            }
            cout << endl;
        }
        
    }
    return 0;
}