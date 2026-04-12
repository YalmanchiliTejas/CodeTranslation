#include <iostream>

using namespace std;

#define RPT(i, n) for (int i = 1; i <= n; i++)

int H, W;
char a[101][101];
bool row_is_white[101];
bool col_is_white[101];

int main()
{
    cin >> H >> W;
    RPT(i, H)
    {
        row_is_white[i] = true;
        RPT(j, W)
        {
            cin >> a[i][j];
            if (row_is_white[i] && a[i][j] == '#') row_is_white[i] = false;
        }
    }

    RPT(j, W)
    {
        col_is_white[j] = true;
        RPT(i, H)
        {
            if (a[i][j] == '#') {
                col_is_white[j] = false;
                break;
            }
        }
    }

    RPT(i, H)
    {
        if (row_is_white[i]) continue;
        RPT(j, W)
        {
            if (col_is_white[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
