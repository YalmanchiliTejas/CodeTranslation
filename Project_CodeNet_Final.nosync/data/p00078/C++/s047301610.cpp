#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<vector<int> > square(n, vector<int>(n, -1));
        int y = n/2 + 1;
        int x = n/2;
        square[y][x] = 1;

        for(int i=2; i<=n*n; ++i){
            ++ y;
            ++ x;
            for(;;){
                if(x == n){
                    x = 0;
                    continue;
                }
                if(x == -1){
                    x = n-1;
                    continue;
                }
                if(y == n){
                    y = 0;
                    continue;
                }
                if(square[y][x] != -1){
                    ++ y;
                    -- x;
                    continue;
                }
                break;
            }
            square[y][x] = i;
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout << setw(4) << square[i][j];
            }
            cout << endl;
        }
    }
}