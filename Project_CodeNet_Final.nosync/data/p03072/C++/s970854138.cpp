#include<bits/stdc++.h>
using namespace std;
int n,ans=1;

int main(){
    scanf("%d",&n);
    int maxx;
    scanf("%d",&maxx);
    for (int i=1,x;i<n;i++)
      scanf("%d",&x),
      ans+=maxx<=x,
      maxx=max(maxx,x);
    printf("%d",ans);
    return 0;
}