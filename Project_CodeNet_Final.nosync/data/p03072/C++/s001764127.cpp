#include<bits/stdc++.h>
#define LL long long
#define Max 100005
const LL mod=1e9+7;
const LL LL_MAX=9223372036854775807;
using namespace std;
int main()
{
    int n,h;
    scanf("%d",&n);
    int now=0,ans=0;
    for(int i=0;i<n;i++){
         scanf("%d",&h);
         if(now<=h)
            ans++;
         now=max(h,now);
    }
    printf("%d\n",ans);
    return 0;
}
