#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> itable(H,vector<char>(W));
    vector<int> del_column, del_row;
    for (int i = 0; i < H;  i++) {
        for (int j = 0; j < W; j++) {
            cin >> itable.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) {
            if(itable.at(i).at(j) != '.') {
                flag = false;
                break;
            }
        }
        if(flag) del_column.push_back(i);
    }
    for (int i = 0; i < W; i++) {
        bool flag = true;
        int j;
        for (j = 0; j < H; j++) {
            if(itable.at(j).at(i) != '.') {
                flag = false;
                break;
            }
        }
        if(flag) del_row.push_back(i);
    }
	
    for (int i = 0; i < H;  i++) {
        bool flag = false;
        for(int c : del_column){
            if (i == c) {
                flag = true;
                //cout << "flagtrue,i:" << i ;
                 break;
            }
        }
        if(flag) continue;
        for (int j = 0; j < W; j++) {
            bool flag = false;
            for(int r : del_row) {
                if(j == r) {
                    flag = true;
                    //cout << "flagtrue,j:" << j ;
                    break;
                }
            }
            if(flag) continue;
            cout << itable.at(i).at(j);

        }
      	cout << endl;
    }
}
