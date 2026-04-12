#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    int h, w;
    cin >> h >> w;
    int start[10];
    int end[10];
    char a[10][10];
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= h; i++){
        start[i] = -1;
        end[i] = -1;
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(a[i][j] == '#'){
                if(start[i] == -1){
                    start[i] = j;
                }
                if(end[i] != -1){
                    cout << "Impossible" << endl;
                    return 0;
                }
            } else {
                if((end[i] == -1) && (start[i] != -1)){
                    end[i] = j - 1;
                }
            }
        }
        if(start[i] == -1){
            cout << "Impossible" << endl;
            return 0;
        }
        if(end[i] == -1){
            end[i] = w;
        }
    }
    for(int i = 1; i < h; i++){
        if(end[i] != start[i + 1]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(a[1][1] == '.'){
            cout << "Impossible" << endl;
            return 0;
    }
    if(a[h][w] == '.'){
            cout << "Impossible" << endl;
            return 0;
    }
    cout << "Possible" << endl;
    return 0;
}