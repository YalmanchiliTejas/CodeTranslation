#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <queue>
#include <iostream>

using namespace std;

#define MAXN 510
#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%s\n", (b * 10 + c) % 4 ? "NO" : "YES");
    return 0;
}
