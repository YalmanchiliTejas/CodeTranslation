#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H,W;
    cin >>H>>W;
    vector<vector<char>> vec(H,vector<char>(W));
    for (int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> vec.at(i).at(j);
        }
        
    }
    vector<bool> row(H,false);
    vector<bool> col(W,false);
    //2こにわけてることで縦の３全部＝true などとできてる
    for( int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(vec.at(i).at(j)=='#'){
                row.at(i)= true;
                col.at(j)= true;
            }
        }
    }
    for(int i=0;i<H;i++){
        if(row.at(i)){
            for(int j=0 ; j<W ; j++){
                if(col.at(j)){
                       cout << vec.at(i).at(j);
                }
            }
          }
          cout<< endl;
    }
}