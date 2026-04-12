#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <random>
#include <cassert>
#include <limits>

using namespace std;

#define mp make_pair
#define pb push_back
#define repi(i, p, q) for (long i = p; i < q; i++)
#define repd(i, p, q) for (long i = p; i >= q; i--)
#define sz(x) x.size()
#define INF 2000000000
#define MOD 1000000007

typedef map<int, int> MI;
typedef pair<int, int> PI;
typedef long long int LLI;
typedef long int LI;
typedef int I;

char a[103][103];
int row[103] = {0};
int col[103] = {0};

int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        int flag = 0;
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == '#')
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            row[i] = 1;
        }
    }
    for (int i = 0; i < w; i++)
    {
        int flag = 0;
        for (int j = 0; j < h; j++)
        {
            if (a[j][i] == '#')
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            col[i] = 1;
        }
    }
    for (int i = 0; i < h; i++)
    {
        int flag = 0;
        for (int j = 0; j < w; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
            }
            else
            {
                flag = 1;
                cout << a[i][j];
            }
        }
        if (flag == 1)
            cout << "\n";
    }
    return 0;
}