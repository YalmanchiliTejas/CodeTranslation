#include <bits/stdc++.h>
using namespace std;

#define   ll     long long int

int cnt[28];
int cur[28];

int main( )
{
    string con[55];
    string s;
    int i, j, k, n;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> con[i];
    }
    for (i = 0; i < (int) con[1].size(); i++) {
        cnt[con[1][i] - 'a']++;
    }
    for (i = 2; i <= n; i++) {
        memset(cur, 0, sizeof cur);
        for (j = 0; j < (int) con[i].size(); j++) {
            int x = con[i][j] - 'a';
            cur[x]++;
        }
        for (int i = 0; i < 26; i++) {
            cnt[i] = min(cnt[i], cur[i]);
        }
    }
    s = "";
    for (i = 0; i < 26; i++) {
        for (j = 0; j < cnt[i]; j++) {
            s.push_back(char(i + 'a'));
        }
    }
    cout << s << '\n';
    return 0;
}