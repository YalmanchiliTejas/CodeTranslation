#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H);
    vector<bool> B(H, true), C(W, true);
    for (int i = 0; i < H; i++)
    {
        vector<char> tmp(W);
        for (int j = 0; j < W; j++)
        {
            cin >> tmp[j];
        }
        A[i] = tmp;
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (A[i][j] != '.')
            {
                B[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (A[j][i] != '.')
            {
                C[i] = false;
                break;
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        if (!B[i])
        {
            for (int j = 0; j < W; j++)
            {
                if (!C[j])
                {
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}