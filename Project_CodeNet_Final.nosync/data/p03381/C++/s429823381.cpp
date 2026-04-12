#include <bits/stdc++.h>

#define fr first
#define sc second

using namespace std;

const int N = 3e5 + 7;

int a[N];
pair<int, int> b[N];
int c[N];

main()
{
    int n, r, l;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i].fr = a[i];
        b[i].sc = i;
    }

    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++)
    {
        c[b[i].sc] = i;
    }

    l = n / 2;
    r = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        int ans;
        if (c[i] <= l)
        {
            ans = b[r].fr;
        }
        else
        {
            ans = b[l].fr;
        }
        printf("%d\n", ans);
    }
}


