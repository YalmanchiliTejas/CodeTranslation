#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 200005 ;
using namespace std ;

int n, a[N] ;

int main() {
    scanf("%d", &n) ;
    rep(i, 1, n) {
        scanf("%d", &a[i]) ;
    }
    int i ;
    for (i = n ; i ; i -= 2) {
        printf("%d ", a[i]) ;
        if (i == 1) break ;
    }
    for (++ i ; i <= n ; i += 2) {
        printf("%d ", a[i]) ;
    }
    return 0 ;  
}