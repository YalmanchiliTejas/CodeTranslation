#include <iostream>
#include <queue>
using namespace std;

char a[101][101];
int r[101], c[101], row, col;

int main()
{
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (a[i][j] == '#')
                break;
            if (j == col)
                a[i][0] = '@';
        }
    }
    for (int i = 1; i <= col; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (a[j][i] == '#')
                break;
            if (j == row)
                a[0][i] = '@';
        }
    }
    
    for (int i = 1, k = 0; i <= row; i++, k = 0)
    {
        for (int j = 1; j <= col; j++)
            if (a[i][0] == '@')
                break;
            else if (a[0][j] == '@')
                continue;
            else
                cout << a[i][j], k = 1;
        if (k == 1 and i < row)
            cout << endl;
    }
    return 0;
}