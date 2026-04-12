#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, X, Y;

    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int ab = min(A + B, C * 2);
    int ans = min(min(min(X, Y) * ab + (X > Y ? (X - Y) * A : (Y - X) * B), max(X, Y) * ab), A * X + B * Y);

    printf("%d\n", ans);

    return 0;
}
