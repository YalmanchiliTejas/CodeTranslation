#include <iostream>

using namespace std;

int main()
{
    char a[200][200];
    bool x[200];
    bool y[200];
    int h, w;
    cin >> h >> w;
    char ch = fgetc(stdin);
    int p = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            a[i][j] = fgetc(stdin);
            if (a[i][j] == '#')
                p = 1;
        }
        if (p == 0) {
            x[i] = 0;
        }
        else
            x[i] = 1;
        p = 0;
        ch = fgetc(stdin);
    }
    p = 0;
    for  (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) {
            if (a[i][j] == '#')
                p = 1;
        }
        if (p == 0)
            y[j] = 0;
        else
            y[j] = 1;
        p = 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (x[i] == 1 && y[j] == 1)
                fputc(a[i][j], stdout);
        }
        if (x[i] == 1)
            cout << "\n";
    }
    return 0;
}
