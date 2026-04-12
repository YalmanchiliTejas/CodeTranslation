#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c,x,y;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    if(a+b>2*c){
        int ans1=max(x,y)*2*c;
        int ans2=min(x,y)*2*c;
        if(x>=y) ans2+=(x-y)*a;
        else ans2+=(y-x)*b;
        printf("%d",min(ans1,ans2));
    }else{
        printf("%d",a*x+b*y);
    }
    return 0;
}