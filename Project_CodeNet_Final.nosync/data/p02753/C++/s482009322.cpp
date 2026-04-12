#include <cstdio>

int main()
{
    // freopen("a.in", "r", stdin);

    char c, pre;
    for(int i = 0; i < 3; i++)
    {
        c = getchar();
        if(i && c != pre) return printf("Yes\n"), 0;
        pre = c;
    }
    printf("No\n");
    return 0;
}