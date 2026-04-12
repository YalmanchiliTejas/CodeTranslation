#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void){
    while (1) {
        string s;
        int a, b, c, d;
        cin >> s;
        if (s == "#") return 0;
        cin >> a >> b >> c >> d;
        a--;  b--;  c--;  d--;
        
        bool board[10][10];
        int bw, bh;
        for (int i = 0; i < 100; i++) board[i/10][i%10] = false;
        int w = 0, h = 0;
        for (int i = 0; i < s.size(); i++) {
            if (char(s[i]) == 'b') board[w][h] = true;
            else if (char(s[i]) == '/') {
                bh = h;
                w++;  h = -1;
            }
            else {
                for (int j = 0; j < int(s[i] - '0') - 1; j++) h++;
            }
            h++;
        }
        bw = w + 1;
        
        board[a][b] = false;
        board[c][d] = true;
        
        int i = 0, j = 0;
        while (i < bw) {
            j = 0;
            while (j < bh) {
                if (board[i][j]) cout << "b";
                else {
                    int idx = 0;
                    while (j + idx < bh && !board[i][j + idx]) idx++;
                    cout << idx;
                    j += idx - 1;
                }
                j++;
            }
            if (i != bw - 1) cout << "/";
            i++;
        }
        cout << endl;
        
    }
}

