#include<cstdio>
#include<algorithm>
#define max 100005

using namespace std;

int s[max];
int main(){
    int x,y,z;
    while( ~scanf("%d%d%d",&x,&y,&z) ){
        int sum=0,ans=0;
        while( sum < x ){
            sum+=(z + y);
            ans++;
        }
        sum-=y;
        ans--;
        if(x >= sum )    printf("%d\n",ans);
        else printf("%d\n",ans-1);
    }
    return 0;
}