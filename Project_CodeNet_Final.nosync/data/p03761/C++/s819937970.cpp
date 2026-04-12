#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 60, mod = 1e9 + 7;

int n;
int res[N];
int str[N][N];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char t[60];
        scanf("%s", t);
        int len = strlen(t);

        for(int j = 0; j < len; j++)
            str[i][t[j] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        int cnt = 0x3f3f3f3f;
        for(int j = 0; j < n; j++) cnt = min(cnt, str[j][i]);
        res[i] = cnt;
    }

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < res[i]; j++)
            printf("%c", i + 'a');

    puts("");

    return 0;
}
