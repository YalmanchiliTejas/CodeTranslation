#include <iostream>

typedef unsigned long long ull;
ull a[55];
ull p[55];

ull func(ull n, ull x){
    if(!n) return 1;
    if(x==1) return 0;
    if(1<x&&x<=(1+a[n-1])){
        return func(n-1, x-1);
    }
    if(x==(2+a[n-1])) return p[n-1]+1;
    if(2+a[n-1]<x&&x<=a[n]-1){
        return (p[n-1]+1+func(n-1, x-2-a[n-1]));
    }
    return 2*p[n-1]+1;
}


int main(){
    ull n, x;
    std::cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }
    std::cout << func(n, x) << std::endl;
}
