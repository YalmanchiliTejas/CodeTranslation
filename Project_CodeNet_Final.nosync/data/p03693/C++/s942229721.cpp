
#include<cstdio>
int main(){
    int r,g,b,x;
    scanf("%d %d %d",&r,&g,&b);
    x=r*100+g*10+b;
    if(x%4==0)
        printf("YES\n");
    else
        printf("NO");
}
