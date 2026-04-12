#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>


typedef long long LL;
using namespace std;
 
void read(int &v) {
    int k = 0, l = 1;
    char ch;
    ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            l = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') k = k * 10 + ch - '0', ch = getchar();
    v = l * k;
}

void print(int v) {
    if (v < 0)
        putchar('-'), v = -v;
    if (v > 9)
        print(v / 10);
    putchar(v % 10 + '0');
}

int max(int a, int b) {
        return a > b ? a : b;
}

int min(int a, int b) {
        return a < b ? a : b;
}

static int a[100005], b[100005];
static int  n;

int main() {
        read(n);
        for (int i=1; i<=n; ++i) {
                scanf("%d",&a[i]);
                a[i]=-a[i];
        }
        int len=1;
        int ans=1;
        int k;
        b[len]=a[1];
        for (int i=2; i<=n; ++i) {
                k=upper_bound(b+1,b+len+1,a[i])-b;
                b[k]=a[i];  
                if (k>len)  {
                    ++ans;
                        ++len;
                }       
        }   
        print(ans);
        return 0;
}