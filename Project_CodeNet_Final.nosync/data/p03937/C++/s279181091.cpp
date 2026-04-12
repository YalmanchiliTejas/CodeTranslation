#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    int H, W, i, j, count=0;
    string A[20];

    cin >> H >> W;

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            cin >> A[i][j];

            if(A[i][j] == '#'){
                count++;
            }
        }
    }

    if(count == H+W-1){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }

    return 0;
}