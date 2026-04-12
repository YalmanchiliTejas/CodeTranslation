#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
long long int a,b,c,x,y;
int total = 0,n;
int main(void)
{
    cin >> a >> b >> c >> x >> y;
    n = x + y;
    if(a + b > 2*c){
        if(x < y){
            total += x * 2 * c;
            n = y - x;
            if(b > 2 * c) cout << total + 2 * c * n;
            else cout << total + b *n;
        }else{
            total += y * 2 * c;
            n = x - y;
            if(a > 2 * c) cout << total + 2 * c * n;
            else cout << total + a *n;
        }
    }else{
        cout << x*a + y*b;
    }
    return 0;
}