#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,x,y;
    int p1=0,p2=0,p3=0,p4=0,p5=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    p1=a*x;
    p2=b*y;
    if(x>y){
        p3=c*y*2;
        p4=(x-y)*a;
        p5=c*x*2;
    }
    else{
        p3=c*x*2;
        p4=(y-x)*b;
        p5=c*y*2;
    }
    if((p1+p2)>(p3+p4)){
        if((p3+p4)>(p5))
        printf("%d\n",p5);
        else
            printf("%d\n",p3+p4);
    }
    else{
        if(p5>(p1+p2))
        printf("%d\n",p1+p2);
        else
            printf("%d\n",p5);
    }
return 0;
}
