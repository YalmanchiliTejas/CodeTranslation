#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    int n;
    if (scanf("%d", &n) < 1) return 0;

    map<char, int> pre;
    map<char, int> cur;
    map<char, int> tmp;
    for (int i = 0; i < n; i++)
    {
        char x[51];
        if (scanf("%s", x) < 1) return 0;

        if (i > 0) for (int j = 0; j < (signed)strlen(x); j++) cur[x[j]]++;
        else for (int j = 0; j < (signed)strlen(x); j++) pre[x[j]]++;

        if (i > 0)
        {
            for (pair<char, int> p : pre)
            {
                // key count
                if (cur.count(p.first) == 0) continue;

                tmp[p.first] = min(cur[p.first], p.second);
            }
            pre.clear();
            cur.clear();
            pre = tmp;
            tmp.clear();
        }
    }

    for (pair<char, int> p : pre)
    {
        for (int i = 0; i < p.second; i++) printf("%c", p.first);
    }

    printf("\n");
    return 0;
}
