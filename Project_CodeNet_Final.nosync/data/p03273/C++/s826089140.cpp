#include<iostream>

#define rep(i, a) for(int i = 0; i < a; i++)
using namespace std;

int main()
{
    int h, w, ct = 0;
    char a[105][105];
    cin >> h >> w;

    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            if (a[i][j] == '.') ++ct;
        }

        if (ct == w) rep(j, w) a[i][j] = '0';
        ct = 0;
    }

    rep(j, w) {
        rep(i, h) if (a[i][j] == '.' || a[i][j] == '0') ct++;
        
        if (ct == h) rep(i, h) a[i][j] = '0';
        ct = 0;
    }

    rep(i, h) {
        rep(j, w) {
            if (a[i][j] != '0') cout << a[i][j];
            else ++ct;
        }

        if(ct != w)cout << endl;
        ct = 0;
    }
}