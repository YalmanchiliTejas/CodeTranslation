#include <iostream>
#include <vector>
using namespace std;
#define rep(i, N) for(int i = 0; i < N;i++)

int main(void){
    // Your code here!
    int H, W;
    cin >> H >> W;
    vector<vector<char>> data(H, vector<char>(W, '\0'));
    rep(i, H) {
        rep(n, W) {
            cin >> data.at(i).at(n);
        }
    }
    bool remove = true;
    rep(i, H) {
        remove = true;
        rep(n, W) {
            if (data.at(i).at(n) != '.')
                remove = false;
        }
        if (remove) {
            rep (n , W) {
                data.at(i).at(n) = '\0';
            }
        }
    }
    rep(i, W) {
        remove = true;
        rep(n, H) {
            if (data.at(n).at(i) == '#')
                remove = false;
        }
        if (remove) {
            rep (n, H) {
                data.at(n).at(i) = '\0';
            }
        }
    }
    rep(i, H) {
        remove = true;
        rep(n, W) {
            if (data.at(i).at(n) != '\0') {
                cout << data.at(i).at(n);
                remove = false;
            }
        }
        if (!remove)
            cout << endl;
    }
}
