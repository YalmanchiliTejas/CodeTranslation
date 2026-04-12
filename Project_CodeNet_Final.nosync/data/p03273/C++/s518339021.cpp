#include <bits/stdc++.h>
using namespace std;


int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));

    for(int i = 0;i < h; i ++){
        for(int j = 0;j < w;j ++){
            cin >> a.at(i).at(j);
        }
    }
    for(int i = 0;i < h; i ++){
        for(int j = 0;j < w;j ++){
            if(a.at(i).at(j) == '#'){
                break;
            }
            if(j == w-1){
                for(int k = 0;k < w; k ++){
                    a.at(i).at(k) ='0';
                }
            }
        }
    }
    for(int i = 0;i < w; i ++){
        for(int j = 0;j < h;j ++){
            if(a.at(j).at(i) == '#'){
                break;
            }
            if(j == h-1){
                for(int k = 0;k < h; k ++){
                    a.at(k).at(i) ='0';
                }
            }
        }
    }



    for(int i = 0;i < h; i ++){
        for(int j = 0; j < w; j ++){
            if(a.at(i).at(j) != '0'){
                cout << a.at(i).at(j);
            }
        }
        for(int j = 0;j < w;j ++){
            if(a.at(i).at(j) != '0'){
                cout << endl;
                break;
            }
        }

    }


}
