#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
int a,b,c,x,y;
scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);

long long ans1=a*x+b*y;
long long ans2,ans3;

int geshu=min(x,y);
int shengyu=max(x,y)-geshu;
if(x>y) {
     ans2 = geshu * c * 2+ shengyu * a;
}else {
    ans2=geshu * c * 2+ shengyu * b;
}
int maxnum=max(x,y);
ans3=maxnum*2*c;

ans1=min(ans1,min(ans2,ans3));

printf("%lld",ans1);
return 0;

}
