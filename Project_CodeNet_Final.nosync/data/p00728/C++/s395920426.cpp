#include <cstdio>
int main()
{
    int n, s[100], i;
    int max, min, ava, sum;
    while (1)
    {
        max = 0;
        min = 1000;
        sum = 0;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
            if (max < s[i])
            {
                max = s[i];
            }
            if (min > s[i])
            {
                min = s[i];
            }
            sum += s[i];
        }
        sum -= max;
        sum -= min;
        ava = sum / (n - 2);
        printf("%d\n", ava);
    }
    return 0;
}

