#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

const int SIZE = 10;
int tile[SIZE][SIZE];
int flip[SIZE][SIZE];

int get(int x, int y)
{
    int c = tile[x][y];

    for (int d = 0; d < 5; ++d) {
        int x2 = x + dx[d];
        int y2 = y + dy[d];

        if (0 <= x2 && x2 < SIZE && 0 <= y2 && y2 < SIZE)
            c += flip[x2][y2];
    }

    return c % 2;
}

bool calc()
{
    for (int i = 1; i < SIZE; ++i) 
        for (int j = 0; j < SIZE; j++) 
            if (get(i - 1, j) != 0) 
                flip[i][j] = 1;

    for (int j = 0; j < SIZE; ++j)
        if (get(SIZE - 1, j) != 0)
            return false;

    return true;
}

void solve()
{
    for (int i = 0; i < 1 << SIZE; ++i) {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < SIZE; ++j) 
            flip[0][SIZE - j - 1] = i >> j & 1;

        if(calc())
            break;
    }

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) 
            cout << flip[i][j] << ((j == SIZE - 1) ? '\n' : ' ');
}

int main()
{
    int n;
    
    cin >> n;
    while (n--) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cin >> tile[i][j];
        solve();
    }

    return 0;
}