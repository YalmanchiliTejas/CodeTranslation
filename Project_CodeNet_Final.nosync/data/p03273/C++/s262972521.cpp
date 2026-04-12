#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> map;
    for(int i = 0 ; i < H; i++){
        vector<char> tmp(W);
        for(int j = 0; j < W; j++){
            cin >> tmp[j];
        }

        if(count(tmp.begin(), tmp.end(), '.') != W){
            vector<char> pushVector;
            for(int j = 0; j < W; j++){
                pushVector.push_back(tmp[j]);
            }

            map.push_back(pushVector);
        }
    }

    for(int j = 0; j < map[0].size(); j++){
        int count = 0;
        for(int i = 0; i < map.size(); i++){
            if(map[i][j] == '.') count++;
        }

        if(count == map.size()){
            for(int i = 0; i < map.size(); i++){
                map[i][j] = '*';
            }
        }
    }


    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] != '*') cout << map[i][j];
        }
        cout << endl;
    }
}