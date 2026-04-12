#include <iostream>
#include <string>

using namespace std;

const int NMAX = 8 + 5;

int n, m;
string mat[NMAX];

bool works(int lin, int col) {
    if (mat[lin][col] != '#')
        return false;
    if (lin == n && col == m)
        return true;

    if (mat[lin + 1][col] == '#')
        return works(lin + 1, col);
    if (mat[lin][col + 1] == '#')
        return works(lin, col + 1);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
        for (auto it: mat[i])
            cnt += (it == '#');

    if (cnt != n + m - 1) {
        cout << "Impossible\n";
        return 0;
    }

    if (works(1, 1))
        cout << "Possible\n";
    else
        cout << "Impossible\n";
    return 0;
}
