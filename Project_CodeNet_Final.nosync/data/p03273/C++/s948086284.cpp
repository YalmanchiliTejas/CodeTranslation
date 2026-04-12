#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main() {
    int H, W, no[100][100] = {};
    char S[100][100];
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        int c = 0;
        for (int j = 0; j < W; j++)
        {
            cin >> S[i][j];
            if (S[i][j] == '.')c++;
        }
        if (c == W) {
            for (int k = 0; k < W; k++)
            {
                no[i][k] = 1;
            }
        }
    }
    for (int i = 0; i < W; i++)
    {
        int c = 0;
        for (int j = 0; j < H; j++)
        {
            if (S[j][i] == '.')c++;
        }
        if (c == H) {
            for (int k = 0; k < H; k++)
            {
                no[k][i] = 1;
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (no[i][j] == 0)cout << S[i][j];
        }
        int c = 0;
        for (int j = 0; j < W; j++)
        {
            if (no[i][j] == 1)c++;
        }
        if (c != W)cout << endl;
    }
}