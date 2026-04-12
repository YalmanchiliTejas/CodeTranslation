#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;
    vector< vector<char> > a;
    for(int i=0; i<H; i++) {
        bool isContainBlack = false;
        vector<char> tmp(W);
        for(int j=0; j<W; j++) {
            cin >> tmp[j];
            if(tmp[j] == '#') {
                isContainBlack = true;
            }
        }
        if(isContainBlack == true) {
            a.push_back(tmp);
        }
    }

    vector<int> ok(W);
    for(int j=0; j<W; j++) {
        for(int i=0; i<a.size(); i++) {
            if(a[i][j] == '#') {
                ok.at(j) = 1;
            }
        }
    }

    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<W; j++) {
            if(ok.at(j)) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
