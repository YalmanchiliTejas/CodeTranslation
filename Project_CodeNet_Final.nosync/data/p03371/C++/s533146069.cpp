#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b,ab,x,y,rs,q;
    scanf("%d %d %d %d %d",&a,&b,&ab,&x,&y);
    if(ab*2>=a+b){
        rs=a*x+b*y;
    }
    else{
        q=min(x,y);
        rs=ab*2*q;
        x-=q;
        y-=q;
        if(ab*2*max(x,y)>=a*x+b*y){
            rs+=a*x+b*y;
        }
        else{
            rs+=ab*2*max(x,y);
        }
    }
    printf("%d\n",rs);
    return 0;
}
