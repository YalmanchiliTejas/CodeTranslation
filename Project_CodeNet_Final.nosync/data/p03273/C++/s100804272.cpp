#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int H,W;

    cin >> H >> W;

    vector<string> S;

    for(int i = 0; i < H; i++){
        string s;
        cin >> s;

        S.push_back(s);
    }

    vector<int> h;
    vector<int> w;

    for(int i = 0; i < W; i++){
        bool flag = false;
        for(int j = 0; j < H; j++){
            if(S[j][i] == '#'){
                flag = true;
            }
        }

        if(flag){
            w.push_back(i);
        }
    }

    for(int i = 0; i < H; i++){
        bool flag = false;
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                flag = true;
            }
        }

        if(flag){
            h.push_back(i);
        }
    }

    for(int i = 0; i < h.size(); i++){
        for(int j = 0; j < w.size(); j++){
            cout << S[h[i]][w[j]];
        }
        cout << endl;
    }
 
    return 0;
}