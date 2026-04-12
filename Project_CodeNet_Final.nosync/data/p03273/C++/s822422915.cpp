#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i=0; i < H; i++){
        cin >> grid[i];
    }

    vector<int> W_no(W, -1);
    for (int i=0; i < W; i++){
        bool loop = false;

        for (int j = 0; j < H; j++){
            if (grid[j][i] == '#'){
                loop = true;
                
               break;
            }
        }

        if (loop == false){
            W_no[i] = i;
                
        }
    }

    string skip(W,'.');
    for (int i = 0; i < H; i++){
        if (grid[i] != skip){
            for (int j = 0; j < W; j++){
                if (count(W_no.begin(), W_no.end(), j) == 0){
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }

}
