#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int i,a,b,c,x,y,t;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    int ans=a*x+b*y;
    for(i=1;i<=x&&i<=y;i++){
        t=ans-(a+b)+2*c;
        ans=min(t,ans);
    }
    for(;i<=x;i++){
        t=ans-a+2*c;
        ans=min(t,ans);
    }
    for(;i<=y;i++){
        t=ans-b+2*c;
        ans=min(t,ans);
    }
    printf("%d\n",ans);
    return 0;
}