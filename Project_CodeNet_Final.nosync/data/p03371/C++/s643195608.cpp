#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y;scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);
    int ans=2e9;
    for(int i=0;i<=max(X,Y)*2;i++){
        int now=C*i;
        now+=A*max(0,(X-i/2))+B*max(0,(Y-i/2));
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}