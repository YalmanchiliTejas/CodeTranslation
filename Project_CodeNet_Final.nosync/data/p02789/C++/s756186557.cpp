// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <bits/stdc++.h>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

int main() {
    int a=read(),b=read();
    if (a==b) puts("Yes");
    else puts("No");
    return 0;
}
