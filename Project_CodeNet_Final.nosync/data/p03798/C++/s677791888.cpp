#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

char s[100001];
char ans[100001];

const char circle = 'o';
const char ex = 'x';

const char S = 'S';
const char W = 'W';

const char *NONE = "-1";
const char yz = '\0';

int N;

void set()
{
    for (int i = 1; i < N - 1; i++)
    {
        if (ans[i] == S && s[i] == circle)
        {
            ans[i + 1] = ans[i - 1];
        }
        else if (ans[i] == S && s[i] == ex)
        {
            ans[i + 1] = ans[i - 1] == S ? W : S;
        }
        else if (ans[i] == W && s[i] == circle)
        {
            ans[i + 1] = ans[i - 1] == S ? W : S;
        }
        else
        {
            ans[i + 1] = ans[i - 1];
        }
    }
}

bool out()
{
    bool flg = false;
    if (s[N - 1] == circle
        && ans[N - 1] == S
        && ans[N - 2] == ans[0])
    {
        flg = !flg;
    }
    else if (s[N - 1] == circle
        && ans[N - 1] == W
        && ans[N - 2] != ans[0])
    {
        flg = !flg;
    }
    else if (s[N - 1] == ex
        && ans[N - 1] == S
        && ans[N - 2] != ans[0])
    {
        flg = !flg;
    }
    else if (s[N - 1] == ex
        && ans[N - 1] == W
        && ans[N - 2] == ans[0])
    {
        flg = !flg;
    }

    // 偽
    if (!flg) return flg;

    ans[N] = yz;
    if (s[0] == circle
        && ans[0] == S
        && ans[N - 1] == ans[1])
    {
        printf("%s\n", ans);
    }
    else if (s[0] == circle
        && ans[0] == W
        && ans[N - 1] != ans[1])
    {
        printf("%s\n", ans);
    }
    else if (s[0] == ex
        && ans[0] == S
        && ans[N - 1] != ans[1])
    {
        printf("%s\n", ans);
    }
    else if (s[0] == ex
        && ans[0] == W
        && ans[N - 1] == ans[1])
    {
        printf("%s\n", ans);
    }
    else
    {
        // 偽
        flg = !flg;
    }

    return flg;
}

int main()
{
    if (scanf("%d", &N) < 1) return 0;

    if (scanf("%s", s) < 1) return 0;

    ans[0] = S;
    ans[1] = S;

    set();
    if (out()) return 0;

    ans[0] = S;
    ans[1] = W;

    set();
    if (out()) return 0;

    ans[0] = W;
    ans[1] = S;

    set();
    if (out()) return 0;

    ans[0] = W;
    ans[1] = W;

    set();
    if (out()) return 0;

    printf("%s\n", NONE);
    return 0;
}
