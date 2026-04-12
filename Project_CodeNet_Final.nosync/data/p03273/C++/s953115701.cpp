#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int H, W;
char a[200][200];
int use_h[200];
int use_w[200];

int main(int argc, char** argv) {
    cin >> H >> W;
    for (int i=0; i<H; i++) cin >> a[i];

    for (int i=0; i<H; i++) for (int j=0; j<W; j++) if (a[i][j] == '#') use_h[i] = 1;
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) if (a[i][j] == '#') use_w[j] = 1;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (use_h[i] && use_w[j]) cout << a[i][j];
        }
        if (use_h[i]) cout << endl;
    }
}