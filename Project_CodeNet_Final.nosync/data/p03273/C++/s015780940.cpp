#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> data(h,vector<char>(w));
    vector<int> H(h);
    vector<int> W(w);

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> data.at(i).at(j);
            if(data.at(i).at(j) == '#') H.at(i) = 1;
        }
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(data.at(j).at(i) == '#') W.at(i) = 1;
        }
    }

    for(int i=0; i<h; i++){
        if(H.at(i) == 0) continue;
        for(int j=0; j<w; j++){
            if(W.at(j) == 0) continue;
            cout << data.at(i).at(j);
        }
        cout << endl;
    }


}
