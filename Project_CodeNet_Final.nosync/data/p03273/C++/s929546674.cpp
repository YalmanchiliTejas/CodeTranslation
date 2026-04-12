#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#define MOD 1000000007
#define INF (1ll<<60)
typedef long long ll;
using namespace std;

char a[100][100];
bool line_1[100]; //falseうめされてる
bool line_2[100];

int main(){
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 100; i++){
        line_1[i] = false;
        line_2[i] = false;
    }

    for (int i = 0; i < h; i++){
        int j;
        for (j = 0; j < w; j++){
            if (a[i][j] == '#') break;
        }
        if (a[i][j] == '#') continue;
        line_1[i] = true;
    }

    for (int j = 0; j < w; j++){
        int i;
        for (i = 0; i < h; i++){
            if (a[i][j] == '#') break;
        }
        if (a[i][j] == '#') continue;
        line_2[j] = true;
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (line_1[i] || line_2[j]) continue;
            cout << a[i][j];
        }
        if (!line_1[i])cout << endl;
    }
}
