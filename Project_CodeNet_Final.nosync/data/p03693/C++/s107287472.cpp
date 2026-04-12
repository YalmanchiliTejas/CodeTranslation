#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main()
{
    const char *YES = "YES";
    const char *NO = "NO";

    int r, g, b;
    if (scanf("%d%d%d", &r, &g, &b) < 3) return 0;

    printf("%s\n", (r * 100 + g * 10 + b) % 4 ? NO : YES);
    return 0;
}
