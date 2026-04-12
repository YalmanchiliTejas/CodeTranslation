#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main () {
    string x;
    cin >> x;
    if (x[0] == 'A' || x[1] == 'A' || x[2] == 'A')
        if (x[0] == 'B' || x[1] == 'B' || x[2] == 'B') { puts("Yes"); return 0; } puts("No");
    return 0;
}