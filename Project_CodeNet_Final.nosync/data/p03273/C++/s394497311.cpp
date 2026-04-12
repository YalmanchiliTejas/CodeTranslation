#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char map[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
        }
    }
  
    bool flag = true;
    vector<vector<char>> tmpmap(h,vector<char>(w));
    int height = 0;
    for(int i=0;i<h;i++){
        flag = false;
        for(int j=0;j<w;j++){
            if(map[i][j]!='.'){
                flag = true;;
                break;
            }
        }
        if(flag){
            for(int j=0;j<w;j++){
                tmpmap.at(height).at(j) = map[i][j];
            }
            height++;
        }
    }

    vector<vector<char>> tmpmap2(h,vector<char>(w));
    int width = 0;
    for(int i=0;i<w;i++){
        flag = false;
        for(int j=0;j<height;j++){
            if(tmpmap[j][i]!='.'){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int j=0;j<height;j++){
                tmpmap2.at(j).at(width) = tmpmap[j][i];
            }
          width++;
          
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout << tmpmap2[i][j];
        }
        cout << endl;
    }
}