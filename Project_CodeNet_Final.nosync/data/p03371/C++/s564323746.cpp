#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
#include <set>
#include <unordered_map>
using namespace std;

int main()
{
//    A B C价格
//    x,y各需要几盒
    int a,b,c,x,y,res=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
//c*2可以一盒A，一盒B；
//    c*2=a+b;
    if(c*2<a && x>y){
        printf("%d",c*2*x);
    }else if(c*2<b && y>x){
        printf("%d",c*2*y);
    }else if(c*2<a+b){
        if(x==y){
            printf("%d",c*2*x);
        }else{
            int needc=min(x,y);
            res=needc*c*2;
            int needa=x-needc,needb=y-needc;
            if(needa>0){
                res=res+needa*a;
            }
            if(needb>0){
                res=res+needb*b;
            }
            printf("%d",res);
        }
    }else{
        res=a*x+b*y;
        printf("%d",res);
    }
    return 0;
}
