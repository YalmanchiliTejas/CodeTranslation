#include<iostream>
using namespace std;

int main()
{
    int h, w, ct = 0;
    char a[105][105];
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') ++ct;
        }

        if (ct == w) 
            for (int j = 0; j < w; j++) a[i][j] = '0';
        ct = 0;
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (a[i][j] == '.' || a[i][j] == '0') ct++;
        }

        if (ct == h)
            for (int i = 0; i < h; i++) a[i][j] = '0';
        ct = 0;
    }


    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != '0') cout << a[i][j];
            else ++ct;
        }

        if(ct != w)cout << endl;
        ct = 0;
    }
}