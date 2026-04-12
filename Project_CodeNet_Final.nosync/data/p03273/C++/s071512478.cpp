#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

int main() {
    int h, w, x[100] = {}, y[100] = {};
    cin >> h >> w;
    string s[100] = {};
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        bool flag=1;
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') flag = 0;
        }
        if (flag) x[i] = 1;
    }
    for (int i = 0; i < w; i++) {
        bool flag = 1;
        for (int j = 0; j < h; j++) {
            if (s[j][i] == '#') flag = 0;
        }
        if (flag) y[i] = 1;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (x[i] == 0 && y[j] == 0) cout << s[i][j];
        }
        if(x[i]==0) cout<<endl;
    }
}