#include <bits/stdc++.h>

using namespace std;

string s[10];
bool u[10][10];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    int i = 0, j = 0;
    while (1){
        u[i][j] = 1;
        if (i > 0 && !u[i - 1][j] && s[i - 1][j] == '#'){
            cout << "Impossible\n";
            return 0;
        }
        if (j > 0 && !u[i][j - 1] && s[i][j - 1] == '#'){
            cout << "Impossible\n";
            return 0;
        }

        int cnt = 0;
        if (i < n && !u[i + 1][j] && s[i + 1][j] == '#')
            cnt++;
        if (j < m && !u[i][j + 1] && s[i][j + 1] == '#')
            cnt++;
        if (cnt == 0)
            break;
        if (cnt > 1){
            cout << "Impossible\n";
            return 0;
        }
        if (i < n && !u[i + 1][j] && s[i + 1][j] == '#'){
            i++;
            continue;
        }

        j++;
        continue;
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (s[i][j] == '#' && !u[i][j]){
        cout << "Impossible\n";
    }

    cout << "Possible\n";
    return 0;
}
