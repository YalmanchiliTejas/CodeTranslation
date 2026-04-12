#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> vec(H, vector<char>(W));

    vector<vector<int>> black_hw(2);
    

    bool insert_h;
    bool insert_w;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> vec.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j == 0)
                insert_h = false;
            
            if (vec.at(i).at(j) == '#')
                insert_h = true;

            if (j == W - 1 && insert_h){
                black_hw.at(0).push_back(i);
            }
        }
        
    }
    

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (j == 0)
                insert_w = false;
            
            if (vec.at(j).at(i) == '#')
                insert_w = true;

            if (j == H - 1 && insert_w){
                black_hw.at(1).push_back(i);
            }
        }
        
    } 
    
    for (int i : black_hw.at(0)){
        
        for (int j : black_hw.at(1)){
            
            cout << vec.at(i).at(j);

            if (j == black_hw.at(1).at(black_hw.at(1).size() - 1)){
                cout << "" << endl;
            }
        }
    } 



    
    
}