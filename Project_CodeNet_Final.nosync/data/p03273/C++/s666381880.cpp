#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back 
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<10)
#define LLINF (1<<30)
#define MOD 1000000007
# define rep(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;

int main() {
    int h, w;
    char grid[100][100];
    vector<int>dh, dw;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        bool yoko = true;
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#')yoko = false;
        }
        if (yoko == false) dh.pb(i);
    }
    for (int i = 0; i < w; i++) {
        bool tate = true;
        for (int j = 0; j < h; j++) {
            if (grid[j][i] == '#')tate = false;
        }
        if (tate == false) dw.pb(i);
    }
    for (int i = 0; i < dh.size(); i++) {
        for (int j = 0; j < dw.size(); j++) {
            cout << grid[dh[i]][dw[j]];
        }
        cout << endl;
    }
    return 0;
}
