#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//这里是简单循环，特别的还是手写吧，或者有的循环用的全局变量也要手写
#define fup(i,a,b) for(int i=a; i<=b; ++i)
#define fwn(i,a,b) for(int i=b; i>=a; --i)

int main()
{
    int L, D, G;
    scanf("%d %d %d", &L, &D, &G);
    printf("%d\n", (L-G)/(D+G));
    return 0;
}