#include<bits/stdc++.h>
using namespace std;
 
 int main (){
     int H,W;
     cin >> H >> W;
     vector<vector<char>> A(H, vector<char>(W));
     for (int i=0; i<H; i++){
         for (int j=0; j<W; j++) {
             cin >> A.at(i).at(j);
         }
     }
     int ans;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++){
            if (A.at(i).at(j) == '#') ans++;
        }
    }
    if (ans == H+W-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
     

 }