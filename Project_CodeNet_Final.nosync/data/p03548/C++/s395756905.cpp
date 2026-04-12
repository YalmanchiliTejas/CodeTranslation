#include<stdio.h>
#define MAX 100001

int X,Y,Z;
int check(int ans)
{
    if ((unsigned long long)Y * ans + Z * (ans + 1) <= X)
        return 1;
    else
        return 0;
}

int upper_bound(int left, int right)
{
    if (right - left == 1)
        return left;
    int mid = left + (right - left) / 2;
    if (check(mid))
        return upper_bound(mid, right);
    else
        return upper_bound(left, mid);
}


int main()
{
    scanf("%d %d %d", &X, &Y, &Z);
    // [1 MAX)
    int ans = upper_bound(-1, MAX);
    if (ans <= 0)
        printf("0\n");
    else
        printf("%d\n", ans);
}
