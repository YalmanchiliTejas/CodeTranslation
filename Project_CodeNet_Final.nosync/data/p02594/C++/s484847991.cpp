#include <bits/stdc++.h>

using namespace std;

#define il inline
#define Rep(i, s, e) for (int i = s; i <= e; ++i)
#define Dep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)

il int read() {
    int x = 0; bool f = true; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = false; c = getchar();}
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? x : -x;
}

int main() {
    printf("%s", read() >= 30 ? "Yes" : "No");
    return 0;
}