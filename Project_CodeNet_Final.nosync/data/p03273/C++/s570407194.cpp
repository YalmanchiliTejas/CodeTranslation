#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int h;
    int w;
    cin >> h >> w;
 
    char sym;
 
    vector<vector<char>> table(h, vector<char>(w));
    //入力する
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> sym;
            table.at(i).at(j) = sym;
        }
    }
    
  
    
    //行を調べて'.'が一行続いたら'.'に'x'を代入する
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table.at(i).size(); ++j) {
            auto itr = find(table.at(i).begin(), table.at(i).end(), '#'); 
            if (itr != table.at(i).end()) {
                break;
            } else {
                for(int k = 0; k < table.at(i).size(); ++k){
                    table.at(i).at(j) = 'x';
                }
                 //table.at(i).erase(table.at(i).begin(), table.at(i).end());
            }
            
        }
    }

    
    //列を調べて'.'or'x'が一列続いたら'.'に'x'を代入する
    //'x'が入ってくれない
    //変数のwとhを使ってる（妥協）
    
    for (int j = 0; j < w; ++j) {
        int i = 0;
        for (i = 0; i < h; ++i) {
            if (table.at(i).at(j) == '#') {
                break;
            }
        }
        if (i == h) {
            for (int k = 0; k < h; ++k) {
                table.at(k).at(j) = 'x';
                //table.at(k).erase(table.at(k).begin()+i);
            }
        }
    }
    
    //表示する
    for(int i = 0; i < table.size(); ++i){
        bool isNotSkip = false;
        for(int j = 0; j < table.at(i).size(); ++j){
            if (table.at(i).at(j) != 'x') {
                cout << table.at(i).at(j);
                isNotSkip = true;
            }
        }
        if ( isNotSkip ) {
            cout << endl;
        }
    }
} 
