#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

typedef long long ll;
using namespace std;

int main()
{
    int h, w;
    char a[100][100];
    int b[100]={0}, c[100]={0};
    
    cin >> h >> w;

    for (int i = 0; i < h; i++){
        for (int j=0; j < w; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (a[i][j] == '#') {
                b[i] = 1;
                c[j] = 1;
            }
        }
    }

    for (int i = 0; i < h; i++){
        if (b[i] > 0) {
            for (int j = 0; j < w; j++){
                if (c[j] > 0) cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}