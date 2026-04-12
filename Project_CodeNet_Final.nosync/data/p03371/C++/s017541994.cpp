#include <stdio.h>

int a, b, c, x, y, ab=0, m;
long long s1=0, s2=0, mini;


int main(){
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    mini = (a*x) + (b*y);
    if(x<y) m=y;
    else    m=x;

    for(int i=0; i<=m; i++){
        if(x < 0) x=0;
        if(y < 0) y=0;
        s1 =(x*a)+(y*b)+(ab*c);

        if(s1 < mini)
            mini = s1;
        x-=1; y-=1; ab+=2;
    }
    printf("%lld\n", mini);
}
