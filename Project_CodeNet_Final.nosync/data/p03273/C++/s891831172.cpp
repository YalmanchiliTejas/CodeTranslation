#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;
const int MAX_HW = 100;
char a[MAX_HW][MAX_HW];

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        } 
    }

    queue<int> row;
    for (int i = 0; i < H; i++){
        bool f = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                f = false;
            }
        }
        if (f) row.push(i);
    }

    queue<int> column;
    for (int j = 0; j < W; j++){
        bool f = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') {
                f = false;
            }
        }
        if (f) column.push(j);
    }
    

    for (int i = 0; i < H; i++) {
        if (!row.empty() && row.front() == i) {
            row.pop();
            continue;
        }

        for (int j = 0; j < W; j++) {
            if (!column.empty() && column.front() == j) {
                column.pop();
                column.push(j);
                continue;
            }

            cout << a[i][j];
        }

        cout << endl;
    }

    return 0;
}