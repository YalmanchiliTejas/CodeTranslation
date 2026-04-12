#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool include(vector<int> a,int value){
    for(int i = 0; i<a.size(); i++){
        if(a.at(i) == value) return true;
    }
    return false;
}

int main() {
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i<H; i++) cin >> a.at(i);
    vector<int> h_del,w_del;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            if(a.at(i).at(j) == '#') break;
            if(j == W-1) h_del.push_back(i);
        }
    }
    for(int i = 0; i<W; i++){
        for(int j = 0; j<H; j++){
            if(a.at(j).at(i) == '#') break;
            if(j == H-1) w_del.push_back(i);
        }
    }
    for(int i = 0; i<H; i++){
        if(include(h_del, i)) continue;
        for(int j = 0; j<W; j++){
            if(include(w_del,j)) continue;
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}
