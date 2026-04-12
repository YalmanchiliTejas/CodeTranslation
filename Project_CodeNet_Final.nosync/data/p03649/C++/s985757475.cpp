#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <sstream>  
#include <iostream>  
#include <algorithm>  
#include <string>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <map>  
#include <set>  
#include <utility>  
   
using namespace std;  
#define LL long long  
#define pb push_back  
#define mk make_pair  
#define pill pair<int, int>  
#define ft first  
#define sd second  
#define mst(a, b)   memset(a, b, sizeof a)  
#define REP(i, x, n)    for(int i = x; i <= n; ++i)  
const int qq = 1e5 + 10;  
const int MOD = 1e9 + 7;  
LL num[60];  
LL p[qq];  
int main(){  
    LL n;   scanf("%lld", &n);  
    for(int i = 0; i < n; ++i) {  
        scanf("%lld", num + i);  
    }  
    LL k = 0;  
    while(1) {  
        int cnt = 0;  
        for(int i = 0; i < n; ++i) {  
            if(num[i] <= n - 1)  cnt++;  
        }  
        if(cnt >= n) break;  
        LL sum = 0;  
        for(int i = 0; i < n; ++i) {  
            p[i] = num[i] / n;  
            sum += p[i];  
        }  
        k += sum;  
        for(int i = 0; i < n; ++i) {  
            num[i] = num[i] - p[i] * n + (sum - p[i]);  
        }  
    }  
    printf("%lld\n", k);  
    return 0;  
}  