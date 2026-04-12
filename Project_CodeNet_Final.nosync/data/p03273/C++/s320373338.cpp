#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

bool isWhite(string s) {
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '.')
        {
            return false;
        }
    }
    return true;
}
int main() {
    int h,w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<int> rowIndex(0);
    vector<int> colIndex(0);
    rep(i,h) {
        if (!isWhite(a[i]))
        {
            rowIndex.push_back(i);
        }
    }
    rep(j,w) {
        bool allWhite = true;
        rep(i,h) {
            if (a[i][j] != '.')
            {
                allWhite = false;
                break;
            }
        }
        if (!allWhite)
        {
            colIndex.push_back(j);
        }
    }
    for (int i = 0; i < rowIndex.size(); i++)
    {
        for (int j = 0; j < colIndex.size(); j++)
        {
            cout << a[rowIndex[i]][colIndex[j]]; 
        }
        cout << endl;
    }
    return 0;
}