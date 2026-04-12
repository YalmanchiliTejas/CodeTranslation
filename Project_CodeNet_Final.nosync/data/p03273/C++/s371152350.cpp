#define _USE_MATH_DEFINES
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
#include <typeinfo>

#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REP1(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREP1(i, x) for (int i = ((int)(x)); i > 0; i--)
/*
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

#define all(x) (x).begin(),(x).end()
*/

using namespace std;

int h, w;
char a[105][105];

void delRow(int r){
    for (int j = 0; j < w;j++)
        a[r][j] = 'D';
}

void delColumn(int c)
{
    for (int i = 0; i < h; i++)
        a[i][c] = 'D';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    for (int i = 0; i < h;i++)
        for (int j = 0; j < w;j++)
            cin >> a[i][j];

    bool needendl[105];
    for (int i = 0; i < 105;i++){
        needendl[i] = true;
    }
        bool allwhite;
    for (int i = 0; i < h;i++){
            allwhite = true;
        for (int j = 0; j < w;j++)
        {
            if(a[i][j]=='#')
                allwhite = false;
        }
        if(allwhite){
            delRow(i);
            needendl[i] = false;
        }
    }
    for (int j = 0; j < w; j++)
    {
        allwhite = true;
        for (int i = 0; i < h; i++)
        {
            if (a[i][j] == '#')
                allwhite = false;
        }
        if (allwhite)
            delColumn(j);
    }
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++){
            if(a[i][j]!='D')
                cout << a[i][j];
        }
        if(needendl[i])
            cout << endl;
    }
}