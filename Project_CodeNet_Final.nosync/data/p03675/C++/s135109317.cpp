#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <ctime>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set>  
#include <utility>  
   
using namespace std;  
#define LL long long  
#define pb push_back  
#define mk make_pair  
#define mst(a, b)   memset(a, b, sizeof a)  
#define REP(i, x, n)    for(int i = x; i <= n; ++i)  
const int qq = 2e5 + 10;  
int a[qq], b[qq];  
   
int main(){  
    int n;  scanf("%d", &n);  
    REP(i, 1, n){  
        scanf("%d", a + i);  
    }  
    int l = 1, r = n;  
    int cnt = 1, p = n;  
    for(int i = n; i >= 1; --i){  
        if(cnt & 1) b[l++] = a[p--];  
        else    b[r--] = a[p--];  
        cnt++;  
    }  
    REP(i, 1, n - 1){  
        printf("%d ", b[i]);  
    }  
    printf("%d\n", b[n]);  
    return 0;  
}  