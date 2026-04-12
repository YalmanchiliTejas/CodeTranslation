#include <iostream>
#include <cstdio>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

int a, b;

int main()
{
    read(a), read(b);
    printf(a == b ? "Yes\n" : "No\n");
    return 0;
}