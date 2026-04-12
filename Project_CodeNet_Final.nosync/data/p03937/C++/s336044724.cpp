#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int ans = 1;
    vector<vector<char>> A(H);
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
        ans += count(A[i].begin(), A[i].end(), '#');
    }
    if (ans == (H + W))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}