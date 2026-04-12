#include<bits/stdc++.h>

int main()
{
    int a, b, c, ab, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    a = std::min(a, c * 2);
    b = std::min(b, c * 2);
    ab = std::min(a + b, c * 2);
    if (x < y)
    {
        printf("%d\n", x * ab + (y - x) * b);
    }
    else
    {
        printf("%d\n", y * ab + (x - y) * a);
    }

	return 0;
}