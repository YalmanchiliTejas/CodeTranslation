#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 1e5 + 10, MAXM = 53, mod = 1e9 + 7;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '0') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int main() {
	int N = read();
	if(N == 7 || N == 5 || N == 3 ) puts("YES");
	else puts("NO");
    return 0;
}
/*
2
4 2
1
2
10 1
5
*/