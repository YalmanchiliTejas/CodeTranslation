#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> white_h(h,false),white_w(w,false);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a.at(i).at(j) == '#'){
                white_h.at(i) = true;
                break;
            }
        }
    }
    for(int j=0; j<w; j++){
        for(int i=0; i<h; i++){
            if(a.at(i).at(j) == '#'){
                white_w.at(j) = true;
                break;
            }
        }
    }

    for(int i=0; i<h; i++){
        if(white_h.at(i)){
            for(int j=0; j<w; j++){
                if(white_w.at(j)){
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}