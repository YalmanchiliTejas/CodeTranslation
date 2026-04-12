#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int h, w;
    cin >> h >> w;
    string *a;
    a = new string[h];
    int i, j;
    for (i = 0; i < h; i++)
        cin >> a[i];

    bool **b;
    b = new bool*[h];
    for (i = 0; i < h; i++) 
    {
        b[i] = new bool[w];
        for (j = 0; j < w; j++)
            b[i][j] = true;
    }
    
    for (i = 0; i < h; i++)
    {
        bool c = false;
        for (j = 0; j < w; j++) 
        {
            if (a[i][j] == '#')
                c = true;
        }

        if (c == false)
        {
            for (j = 0; j < w; j++)
                b[i][j] = false;
        }
    }

    for (i = 0; i < w; i++) {
        bool c = false;
        for (j = 0; j < h; j++)
        {
            if (a[j][i] == '#')
                c = true;
        }
        if (c == false)
        {
            for (j = 0; j < h; j++)
                b[j][i] = false;
        }
    }

    for (i = 0; i < h; i++) {
        bool c = false;
        for (j = 0; j < w; j++) {
            if (b[i][j] == true) {
                cout << a[i][j];
                c = true;
            }
        }
        if (c)
            cout << endl;
    }

    return 0;
}