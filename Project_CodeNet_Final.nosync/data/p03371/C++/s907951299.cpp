#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,x,y,total=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if (x*y != 0){
        if (2*c<a+b){
            int minval = min(x,y);
            x-=minval;
            y-=minval;
            total += 2*c * minval;
        }
    }
    if (x!=0){
        if (2*c<a){
            total += 2*c*x;
            x=0;
        }else
            total += a*x;
    }
    if (y!=0){
        if (2*c<b){
            total += 2*c*y;
        }else
            total += b*y;
    }
    printf("%d",total);
    
    
    return 0;
}
