#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const int MAX = 100;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > d(n+1, vector<int>(m+1));
    for(int x=1; x<=n; ++x){
        for(int y=1; y<=m; ++y){
            cin >> d[x][y];
        }
    }

    int size = 2 * MAX + 2;
    vector<tuple<int, int, int>> ans;
    for(int i=0; i<MAX; ++i)
        ans.push_back(make_tuple(i, i+1, -1));
    for(int i=0; i<MAX; ++i)
        ans.push_back(make_tuple(size-2-i, size-1-i, -2));

    vector<vector<bool> > check(n+1, vector<bool>(m+1, false));
    int cnt = n * m;
    for(int a=0; a<=MAX; ++a){
        for(int b=0; b<=MAX; ++b){
            int c = 0;
            for(int x=1; x<=n; ++x){
                for(int y=1; y<=m; ++y){
                    int tmp = d[x][y] - a * x - b * y;
                    c = max(c, tmp);
                }
            }
            for(int x=1; x<=n; ++x){
                for(int y=1; y<=m; ++y){
                    int tmp = d[x][y] - a * x - b * y;
                    if(tmp == c && !check[x][y]){
                        check[x][y] = true;
                        -- cnt;
                    }
                }
            }
            if(c <= MAX)
                ans.push_back(make_tuple(a, 2*MAX+1-b, c));
        }
    }

    if(cnt == 0){
        cout << "Possible" << endl;
        cout << size << ' ' << ans.size() << endl;
        for(const auto& t : ans){
            int a, b, c;
            tie(a, b, c) = t;
            ++ a;
            ++ b;
            cout << a << ' ' << b << ' ';
            if(c == -1)
                cout << 'X' << endl;
            else if(c == -2)
                cout << 'Y' << endl;
            else
                cout << c << endl;
        }
        cout << 1 << ' ' << size << endl;
    }
    else{
        cout << "Impossible" << endl;
    }

    return 0;
}
