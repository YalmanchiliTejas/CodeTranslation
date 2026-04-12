#include <cstdio>

using namespace std;

char a, b, c;

int main()
{
    scanf(" %c%c%c", &a, &b, &c);
    if (a == b && b == c) printf("No\n");
    else printf("Yes\n");
    return 0;
}