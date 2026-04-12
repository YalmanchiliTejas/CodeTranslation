#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    bool solution = false, c1, c2;
    string s;
    cin >> n >> s;
    int f[n];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (solution == true) break;
            c1 = false;
            c2 = false;
            f[0] = i;
            f[1] = j;
            for (int k = 2; k < n; k++)
            {
                if (f[k - 1] == 1 && s[k - 1] == 'o')
                    f[k] = f[k - 2];
                if (f[k - 1] == 1 && s[k - 1] == 'x')
                    f[k] = (f[k - 2] + 1) % 2;
                if (f[k - 1] == 0 && s[k - 1] == 'o')
                    f[k] = (f[k - 2] + 1) % 2;
                if (f[k - 1] == 0 && s[k - 1] == 'x')
                    f[k] = f[k - 2];
            }
            if (s[0] == 'o' && (f[1] == f[n - 1]) == f[0]) c1 = true;
            if (s[0] == 'x' && (f[1] != f[n - 1]) == f[0]) c1 = true;
            if (s[n - 1] == 'o' && (f[0] == f[n - 2]) == f[n - 1]) c2 = true;
            if (s[n - 1] == 'x' && (f[0] != f[n - 2]) == f[n - 1]) c2 = true;
            if (c1 == true && c2 == true)
            {
                solution = true;
                for (int i = 0; i < n; i++)
                {
                    if (f[i] == 1) cout << 'S';
                    else cout << 'W';
                }
            }
        }
    }
    if (solution == false) cout << "-1";
}