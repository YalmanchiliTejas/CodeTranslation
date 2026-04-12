#include <cstdio>
#include <algorithm>

using namespace std;
int n;

int main()
{
    scanf("%d", &n);
    printf("%d\n", n*800 - (n/15)*200);
    return 0;
}