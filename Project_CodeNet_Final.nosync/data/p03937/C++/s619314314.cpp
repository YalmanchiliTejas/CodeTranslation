#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int covered(vector<char> a, vector<char> b) {
    int n = a.size()-1;

    while(a[n]=='.' && n>0) {
        n--;
    }

    /*for(int i = 0; i < a.size(); i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < a.size(); i++) {
        printf("%c ", b[i]);
    }
    printf("[%d]\n", n);*/

    // #がない
    if(n >= a.size()) return -1;
    // 上の段の#よりも左側に#がある
    for(int i = 0; i < n; i++) {
        if(b[i]=='#') return -1;
    }

    return 1;
}

int main() {
    int h, w;
    cin >> h; cin >> w;

    vector<vector<char>> board;
    for(int i = 0; i < h; i++) {

        vector<char> row;
        for(int j = 0; j < w; j++) {
            char a; cin >> a;
            row.push_back(a);
        }
        board.push_back(row);
    }

    for(int i = 0; i < h-1; i++) {
        vector<char> a = board[i];
        vector<char> b = board[i+1];

        if(covered(a,b) == -1) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}