#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    int i,j;
    vector<bool> b(H);
    vector<bool> c(W);

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            cin >> a.at(i).at(j);
        }
    }

    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(a.at(i).at(j)=='#'){
                b.at(i)=true;
                c.at(j)=true;
            }
        }
    }

    for(i=0; i<H; i++){
        if(b.at(i)){
            for(j=0; j<W; j++){
                if(c.at(j)) cout << a.at(i).at(j);
            }
            cout << endl;
        }
    }

    return 0;
}