#include <bits/stdc++.h>
using namespace std;

int h, w;
char grid[500][500];
char tempgrid[500][500];

int rowCheck() {
    for (int i = 0;  i < h; i++) {
        bool rowWhite = true;
        for  (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
                rowWhite = false;
        
        if (rowWhite == true)
            return i;
    }
    return -1;
}
int colCheck() {
    for (int j = 0;  j < w; j++) {
        bool colWhite = true;
        for  (int i = 0; i < h; i++)
            if (grid[i][j] == '#')
                colWhite = false;
        
        if (colWhite == true)
            return j;
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    
    while (rowCheck() != -1) {
        int delrow = rowCheck();
        if (delrow == -1)
            break;
        for (int i = 0; i < h; i++) {
            for (int j = 0;  j < w; j++)
                if (i < delrow)
                    continue;
                else
                    grid[i][j] = grid[i+1][j];
        }
        h--;
    }
    
    while (colCheck()!= -1) {
        int delcol = colCheck();
        //cout << "delcol: " << delcol << endl;
        if (delcol == -1)
            break;
        for (int j = 0; j < w; j++) {
            for (int i = 0;  i < h; i++)
                if (j < delcol)
                    continue;
                else
                    grid[i][j] = grid[i][j+1];
        }
        w--;
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << grid[i][j];
        cout << endl;
    }
    
    return 0;
}
