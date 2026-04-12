#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long getCtOfP(int n)
{
    long long a = 1;
    for(int i = 0; i <= n; i++){
        if(i != 0){
            a *= 2;
            a += 1;
        }
    }
    return a;
}


long long getCtOfAll(int n)
{
    long long a = 1;
    for(int i = 0; i <= n; i++){
        if(i != 0){
            a *= 2;
            a += 3;
        }
    }
    return a;
}

long long mkbg(int n, long long x)
{
    long long bgct = getCtOfAll(n);
    long long sum = 0;

    if(x == 0){
        return 0;
    }

    if(x == bgct){
        return getCtOfP(n);
    }

    if(bgct/2+1 == x){
        return getCtOfP(n-1)+1;
    }else if(bgct/2 < x){
        sum += getCtOfP(n-1) + 1 + mkbg(n-1, (x-bgct/2)-1);
    }else{
        sum += mkbg(n-1, x-1);
    }
    return sum;
}


int main(void)
{
    long long n,x;
    cin >>n >>x;

    long long ans = mkbg(n, x);

    printf("%lld\n", ans);
//    printf("%lld\n", getCtOfAll(n));
    return 0;
}