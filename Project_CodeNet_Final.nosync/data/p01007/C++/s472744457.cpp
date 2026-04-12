#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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
#include <functional>
using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {-1, 1, 0, 0};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[i][j];
        }
    }

    while(--m >= 0){
        int ope;
        cin >> ope;
        if(ope == 0){
            int r, c, size, angle;
            cin >> r >> c >> size >> angle;
            -- r;
            -- c;

            while(angle > 0){
                vector<vector<int> > b = a;
                for(int i=0; i<size; ++i){
                    for(int j=0; j<size; ++j){
                        a[r+i][c+j] = b[r+size-1-j][c+i];
                    }
                }
                angle -= 90;
            }
        }
        else if(ope == 1){
            int r, c, size;
            cin >> r >> c >> size;
            -- r;
            -- c;
            for(int i=0; i<size; ++i){
                for(int j=0; j<size; ++j){
                    a[r+i][c+j] ^= 1;
                }
            }
        }
        else if(ope == 2){
            int r;
            cin >> r;
            -- r;
            rotate(a[r].begin(), a[r].begin()+1, a[r].end());
        }
        else if(ope == 3){
            int r;
            cin >> r;
            -- r;
            rotate(a[r].begin(), a[r].end()-1, a[r].end());
        }
        else{
            int r, c;
            cin >> r >> c;
            -- r;
            -- c;
            int num = a[r][c];
            a[r][c] = num ^ 1;

            queue<pair<int, int> > q;
            q.push(make_pair(r, c));
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int i=0; i<4; ++i){
                    int y2 = y + dy[i];
                    int x2 = x + dx[i];
                    if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= n)
                        continue;
                    if(a[y2][x2] == num){
                        a[y2][x2] = num ^ 1;
                        q.push(make_pair(y2, x2));
                    }
                }
            }
        }
    }

    for(int i=0; i<n; ++i){
        cout << a[i][0];
        for(int j=1; j<n; ++j)
            cout << ' ' << a[i][j];
        cout << endl;
    }

    return 0;
}