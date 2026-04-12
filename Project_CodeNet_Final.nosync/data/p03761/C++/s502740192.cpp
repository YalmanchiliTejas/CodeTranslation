#include <bits/stdc++.h>
using namespace std;

int main()
{
    int total[27];
    for (int i = 0; i <= 26; i++) total[i] = 1000000;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int tmp[27] = {};
        for (int i = 0; i < (int)s.size(); i++) tmp[s[i] - 'a']++;
        for (int i = 0; i <= 26; i++) total[i] = min(total[i], tmp[i]);
    }

    for (int i = 0; i <= 26; i++) {
        for (int j = 1; j <= total[i]; j++) {
            printf("%c", i + 'a');
        }
    }
}
