#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int H,W;
    cin >> H >> W;
    int count = 0;
    vector<vector<char> > data(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> data.at(i).at(j);
            if (data.at(i).at(j) == '#'){
                count++;
            }
        }
    }

    if (count != H + W - 1){
        cout << "Impossible" << endl;
        return 0;
    }
    
    int j = 0;
    int k = 0;
    for (int i = 0; i < H+W-1; i++) {
        if (j == H-1 && k == W-1){
            cout << "Possible" << endl;
            return 0;
        }
        else if (j == H-1){
            if (data.at(j).at(k+1) == '#'){
                k++;
            }
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        else if (k == W-1){
            if (data.at(j+1).at(k) == '#'){
                j++;
            }
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        else {
            if (data.at(j).at(k+1) == '#'){
                k++;
            }
            else if (data.at(j+1).at(k) == '#'){
                j++;
            }
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
}




    