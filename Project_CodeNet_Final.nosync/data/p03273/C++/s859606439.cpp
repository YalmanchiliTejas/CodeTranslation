#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    int H,W;
    cin >> H >> W;
    char tile[H+1][W+1];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> tile[i][j];
        }
    }

    bool skip_h[H], skip_w[W];
    memset(skip_h, 0, sizeof(skip_h));
    memset(skip_w, 0, sizeof(skip_w));
    for(int h=0; h<H; h++){
        bool flag=true;
        for(int w=0; w<W; w++){
            if(tile[h][w]!='.') flag=false;
        }
        skip_h[h]=flag;
    }
    for(int w=0; w<W; w++){
        bool flag=true;
        char tmp=tile[0][w];
        for(int h=0; h<H; h++){
            if(tile[h][w]!='.') flag=false;
        }
        skip_w[w]=flag;
    }
    for(int h=0; h<H; h++){
        if(skip_h[h]==true) continue;
        for(int w=0; w<W; w++){
            if(skip_w[w]==true) continue;
            cout << tile[h][w];
        }
        cout << endl;
    }

    return 0;
}