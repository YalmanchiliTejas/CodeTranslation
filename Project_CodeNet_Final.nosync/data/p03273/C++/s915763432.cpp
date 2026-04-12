#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char> > A(H,vector<char> (0));
    for (int i = 0; i < H; i++){
        string gyou;
        cin >> gyou;
        for (int j = 0; j < W; j++){
            A.at(i).push_back(gyou.at(j));
        }
    }
    for (int i = W - 1; i >= 0; i--){
        int retsu_count = 0;
        for (int j = 0; j < H; j++){
            if (A.at(j).at(i) == '.'){
                retsu_count++;
            }
        }
        if (retsu_count == H){
            for (int j = 0; j < H; j++){
                A.at(j).erase(A.at(j).begin() + i);
            }
        }
    }
    
    for (int i = 0; i < H; i++){
        int gyou_count = 0;
        int retsu_su = A.at(i).size();
        for (int j = 0; j < retsu_su; j++){
            if (A.at(i).at(j) == '.'){
                gyou_count++;
            }
        }
        if (gyou_count != retsu_su){
            for (int j = 0; j < retsu_su; j++){
                cout << A.at(i).at(j);
            }
            cout << endl;
        }
    }
}