#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> mass(H,vector<char>(W,'.'));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c;
            cin >> c;
            if(mass.at(i).at(j) != c){
                mass.at(i).at(j) = c;
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(mass.at(i).at(j) == '#'){
                break;
            }
            if(j==W-1){
                for(int k=0;k<W;k++){
                    mass.at(i).at(k) = '@';
                }
            }
        }
    }
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(mass.at(i).at(j) == '#'){
                break;
            }
            if(i==H-1){
                for(int k=0;k<H;k++){
                    mass.at(k).at(j) = '@';
                }
            }
        }
    }
    for(int i=0;i<H;i++){
        int count=0;
        for(int j=0;j<W;j++){
            if(mass.at(i).at(j) != '@'){
                cout << mass.at(i).at(j);
                count++;
            }
        }
        if(count){
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}