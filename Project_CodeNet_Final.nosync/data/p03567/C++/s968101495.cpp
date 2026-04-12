#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
char s[maxn];
int main()
{
    while (cin >> s) {
        int ok = 0;
        for (int i = 0; i <strlen(s) - 1; i++)
            if (s[i] == 'A' && s[i + 1] == 'C')
                ok = 1;
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
