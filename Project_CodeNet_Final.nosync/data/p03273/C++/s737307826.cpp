#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define MMP(a, b, c) make_pair(make_pair(a, b), c)
#define MAX 1000000000
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define PI 3.14159265359

int main(){
    iostream::sync_with_stdio(false);

    int H,W;
    cin >> H >> W;
    char a[100][100];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> a[i][j];
        }
    }

    bool h[100] = {};
    for(int i=0; i<H; i++){
        bool tmp = true;
        for(int j=0; j<W; j++){
            tmp = tmp && (a[i][j] == '.');
        }
        if(tmp) h[i] = true;
    }
    bool w[100] = {};
    for(int i=0; i<W; i++){
        bool tmp = true;
        for(int j=0; j<H; j++){
            tmp = tmp && (a[j][i] == '.');
        }
        if(tmp) w[i] = true;
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(h[i] == false && w[j] == false) cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
