#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;

    while(scanf("%d%d%d%d%d",&a,&b,&c,&x,&y)==5){
        int ApB = x*a + y*b;
        int minAB;

        if(x<y){
            minAB = 2*x*c + (y-x)*b;
        }

        else{
            minAB = 2*y*c + (x-y)*a;
        }

        int maxAB = max(x,y)*2*c;
        int ans = min(ApB, min(minAB, maxAB));

        printf("%d\n",ans);
    }

    return 0;
}
