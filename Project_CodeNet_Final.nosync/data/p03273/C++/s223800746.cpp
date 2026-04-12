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
#include <bitset>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main(void){

    int H,W;
    cin >> H >> W;
    char a[H][W];


    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }

    int row[H] = {0};
    for(int i = 0; i < H; i++){
        int c = 0;
        for(int j = 0; j < W; j++){
            if(a[i][j] == '.'){
                c++;
            }
        }
        if(c==W) row[i]++;//row.push_back(i);
    }

    int col[W] = {0};
    for(int i = 0; i < W; i++){
        int d = 0;
        for(int j = 0; j < H; j++){
            if(a[j][i] == '.'){
                d++;
            }
        }
        if(d==H) col[i]++;
    }


    for(int i = 0; i < H; i++){
        if(row[i]) continue;

        for(int j = 0; j < W; j++){
            if(col[j]) continue;

            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}