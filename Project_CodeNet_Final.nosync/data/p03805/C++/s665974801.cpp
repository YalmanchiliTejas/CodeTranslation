#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <string.h>
#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
#define LL long long
#define eps 1e-6
using namespace std;
const double pi = 3.1415926535;
/*
https://codeforces.com/contest/1106/problems
https://codeforces.com/contest/1106/submit
*/
int num = 0;
int a[10][10];
int n,m;
int dfs(int temp[10],int x){
    for(int i = 1; i <= n; i ++){
        if(temp[i] == 0){
            goto l;
        }else{

        }
    }
    num ++;
    return 0;
    l:0;
    for(int i = 1; i <= n; i ++){
        if(a[x][i] == 1 && temp[i] == 0){
            temp[i] = 1;
            dfs(temp,i);
            temp[i] = 0;
        }
    }
    return 0;
}

int main() {
    s(n) s(m)
    re(a,0);
    int x,y;
    for(int i = 0; i < m; i ++){
        s(x) s(y)
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int temp[10];
    re(temp,0);
    temp[1] = 1;
    dfs(temp,1);
    p(num) pn
    return 0;
}



 //1 1 1 1 2 2 2 3 3 5 6 6 8 8 11
