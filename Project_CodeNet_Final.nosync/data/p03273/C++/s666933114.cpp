#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <climits>
#include <list>
#include <time.h>
#include <unordered_map>
#include <bitset>
#include <exception>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define FILE "file"
#define lc v << 1
#define rc (v << 1) + 1
#define inf 1e+9
#define linf ll(1e+18)
#define dinf 1e+14

typedef long long ll;
#define pb push_back
#define mp make_pair

char grid[100][100];
vector<int> rows, columns;

void solve()
{
    int H, W;
    cin >> H >> W;
    rows.assign(H, 0);
    columns.assign(W, 0);
    for(int i = 0; i < H; i++)
    {
        for(int k = 0; k < W; k++)
        {
            cin >> grid[i][k];
            if(grid[i][k] == '#')
            {
                rows[i] = 1;
                columns[k] = 1;
            }
        }
    }
    
    for(int i = 0; i < H; i++)
    {
        if(rows[i] == 0)
        {
            continue;
        }
        
        for(int k = 0; k < W; k++)
        {
            if(columns[k] == 0)
            {
                continue;
            }
            
            cout << grid[i][k];
        }
        
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen(FILE ".in", "r", stdin);freopen(FILE ".out", "w", stdout);
    //freopen("file.in", "r", stdin);freopen("file.out", "w", stdout);
    int t = 1;
    //cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}
