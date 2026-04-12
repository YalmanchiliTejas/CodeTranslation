#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int cnt = 0, opt = 1;
    char ch = getchar();

    for (; ! isalnum(ch); ch = getchar())
        if (ch == '-')  opt = 0;
    for (; isalnum(ch); ch = getchar())
        cnt = cnt * 10 + ch - 48;

    return opt ? cnt : -cnt;
}

int n, m;

int main() {
	n = read(), m = read();
	
	printf("%s", n == m ? "Yes" : "No");
    return 0;
}