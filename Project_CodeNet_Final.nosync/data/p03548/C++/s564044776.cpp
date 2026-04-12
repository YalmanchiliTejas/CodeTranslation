#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int ans = (x - z) / (y + z);
    printf("%d\n", ans);
    return 0;
}