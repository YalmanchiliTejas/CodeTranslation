#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    printf("%d\n", min(x * a + y * b,min(max(x, y) * c * 2, x > y ? y * c * 2 + (x - y) * a : x * c * 2 + (y - x) * b)));
    return 0;
}
