#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    vector<bool> allh(h, false), allw(w, false);
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j++){
            if(j == w-1 && a[i][j] == '.') allh[i] = true;
            if(a[i][j] == '.') continue;
            else break;
        }
    }

    for(int i = 0; i < w; i ++){
        for(int j = 0; j < h; j++){
            if(j == h-1 && a[j][i] == '.') allw[i] = true;
            if(a[j][i] == '.') continue;
            else break;
        }
    }

    for(int i = 0; i < h; i++){
        if(allh[i]) continue;
        for(int j = 0; j < w; j++){
            if(allw[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}