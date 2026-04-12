#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main() {
    int t = read();
    if(t >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}