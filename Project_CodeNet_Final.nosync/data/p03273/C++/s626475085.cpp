#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

typedef int itn;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef map<int, int> M;
typedef pair<int, int> P;
typedef stack<int> S;
typedef queue<int> Q;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; ++i)
    {
        cin >> s[i];
    }

    int row[h] = {0};
    int col[w] = {0};
    
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (s[i][j] == '#') row[i] = col[j] = 1;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if ((row[i] == 1) && (col[j] == 1)) cout << s[i][j];
        }
        if (row[i] == 1) cout << endl;
    }

    return 0;
}