#include <bits/stdc++.h>
using namespace std;

inline long long read(){
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

int main(){
    int x = read();
    if (x >= 30) puts("Yes");
    else puts("No");
    return 0;
}