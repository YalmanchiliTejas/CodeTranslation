#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
    int h, w;
    int i, j;
    
    cin >> h >> w;
    
    char a[h][w];
    int judgey[h];
    int judgex[w];
    
    for(i = 0; i < h; i++) { judgey[i] = 0; }
    for(j = 0; j < w; j++) { judgex[j] = 0; }
    
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                judgey[i] = 1;
                judgex[j] = 1;
            }
        }
    }
    
    for(i = 0; i < h; i++) {
        if(judgey[i] == 1) {
            for(j = 0; j < w; j++) {
                if(judgex[j] == 1) {
                    cout << a[i][j];
                }
            }
        cout << endl;
        }
    }
    
    return 0;
}
