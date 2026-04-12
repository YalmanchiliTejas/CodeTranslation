#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
void Unused(...) {}
#ifndef DEBUG
  #define echo(...) Unused(__VA_ARGS__)
#else
  #define echo(...) fprintf(stderr, __VA_ARGS__)
#endif

const int MaxN = 1e5 + 7;

int n;
int val[MaxN];
std::vector<int> rest[MaxN];
int len;

/*
 * int idx[MaxN];
 * int lis()
 * {
 *   int len = 0;
 *   for (int i = 1; i <= n; ++i)
 *   {
 *     if (val[i] > val[idx[len]])
 *       idx[++len] = val[i];
 *     else
 *       *upper_bound(idx, idx + len + 1, val[i]) = val[i];
 *   }
 *   return len;
 * }
 */

int find(int v)
{
    int l = 1, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (v > rest[mid].back())
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", val + i);
    rest[len = 1].push_back(val[1]);
    for (int now = 2; now <= n; ++now)
    {
        int ins = find(val[now]);
        //echo("find %d(%d %d)\n", ins);
        if (ins == len && val[now] <= rest[ins].back())
            rest[++len].push_back(val[now]);
        else
            rest[ins].push_back(val[now]);
    }
    /*
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 0; j < rest[i].size(); ++j)
            echo("%d ", rest[i][j]);
        echo("\n");
    }
    */
    printf("%d\n", len);
    return 0;
}

