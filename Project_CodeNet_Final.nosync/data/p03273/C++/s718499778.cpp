
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    
    vector<vector<char>> a(H,vector<char>(W));
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> a.at(i).at(j);
        }
    }
    
    vector<bool> line(H,true);
    vector<bool> row(W,true);
    
    
    int L_counter=0;
    int R_counter=0;
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if(a.at(i).at(j) != '.'){
                line.at(i) = false;
                break;
            }
        }
        if(line.at(i)){
            L_counter++;
        }
    }
    
    for (int j=0; j<W; j++) {
        for (int i=0; i<H; i++) {
            if(a.at(i).at(j) != '.'){
                row.at(j) = false;
                break;
            }
        }
        if(row.at(j)){
            R_counter++;
        }
    }
    
    /*
    cout <<endl;
    
    int x = H - L_counter;
    int y = W - R_counter;
    vector<vector<int>> G(x, vector<int>(y));
    vector<int> op(x*y);
    int c=0;
    */
    
    for (int i=0; i<H; i++) {
        if(line.at(i)){
            continue;;
        }
        for (int j=0; j<W; j++) {
            if(row.at(j)){
                continue;
            }
            else{
                cout << a.at(i).at(j);
            }
        }
        cout <<endl;
    }
}
