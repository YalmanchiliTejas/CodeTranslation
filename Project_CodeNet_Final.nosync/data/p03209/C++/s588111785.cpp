#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

long int f(int L, long int X);

using namespace std;
long int a[50];
long int p[50];

int main(){
    int N;
    long int X;
    cin >> N >> X ;

    a[0] = 1;
    for(int i = 1; i < 50 ; i++){
        a[i] = 2*a[i-1] + 3;
    }
    p[0] = 1;
    for(int i = 1; i < 50; i++){
        p[i] = 2*p[i-1] + 1;
    }

    cout << f(N,X) << endl;

    return 0;
    
}

long int f(int L, long int X){
    long int ans = 0;
    if(L == 0){
        return 1;
    }else{
        if(X == 1) ans = 0;
        if(1 < X && X <= 1 + a[L-1]) ans = f(L -1 , X-1);
        if(X == 2 + a[L-1]) ans = p[L-1] + 1;
        if(2 + a[L-1] < X && X <= 2 + 2*a[L-1] ) ans = 1 + p[L-1] + f(L-1 , X - 2 - a[L-1] );
        if(X == 3 + 2*a[L-1]) ans = 2*p[L-1] + 1 ;

        return ans; 
    }
}