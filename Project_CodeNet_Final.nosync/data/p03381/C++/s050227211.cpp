#include <bits/stdc++.h>

using namespace std ;

const int MAXN(200000 + 10);
int n ;
int a[MAXN] ;
int b[MAXN] ;

int main(){
    scanf("%d" , &n) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d" , &a[i]) ;
        b[i] = a[i] ;
    }

    sort(b , b + n) ;

    int h = b[n / 2 - 1] ;
    int hh = b[n / 2] ;


    for(int i = 0 ; i < n ; i ++){
        if(a[i] <= h) printf("%d\n" , hh) ;
        else printf("%d\n" , h) ;
    }
}
