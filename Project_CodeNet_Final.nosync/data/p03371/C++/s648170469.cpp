#include<stdio.h>
int min(int a, int b ){
    if (a<b) return a; else return b;
}
int main( ){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int ans=0;
    c*=2;
    if (c<(a+b)) {
        ans=min(d,e)*c;
    }else{
        ans=a*(min(d,e))+b*min(d,e);
    }
    if (c<a) ans+=c*(d-min(d,e));else ans+=a*(d-min(d,e));
    if (c<b) ans+=c*(e-min(d,e));else ans+=b*(e-min(d,e));
    printf("%d",ans);
}
