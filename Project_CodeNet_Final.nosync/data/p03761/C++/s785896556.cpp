#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[26], t[26];
    cin >> n;
    for (int i = 0; i < 26; i++) t[i] = 0;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < 26; j++) a[j] = 0;
        for (int j = 0; j < s[i].length(); j++)
            a[int(s[i][j]) - 97]++;
        for (int j = 0; j < 26; j++)
        {
            if (i == 0) t[j] = a[j];
            else t[j] = min(t[j], a[j]);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (t[i] > 0)
            for (int j = 0; j < t[i]; j++) cout << char(i + 97);
    }
}