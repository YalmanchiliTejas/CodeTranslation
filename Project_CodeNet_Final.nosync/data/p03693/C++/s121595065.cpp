//It is made by wfj_2048~
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define inf (1<<30)
#define il inline
#define RG register
#define ll long long

using namespace std;

int r,g,b;

il int gi(){
    RG int x=0,q=1; RG char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

il void work(){
    r=gi(),g=gi(),b=gi();
    if ((g*10+b)%4==0) puts("YES");
    else puts("NO"); return;
}

int main(){
    work();
    return 0;
}
