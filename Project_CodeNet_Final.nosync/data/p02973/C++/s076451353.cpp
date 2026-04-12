#include<bits/stdc++.h>
#define ll long long
#define INF 1999122700
using namespace std;
int n;
int a[200004],f[200004];
map<int,int>mert;
bool check(int len,int x){
    return (mert[len-1]>=x);
}
int main(){
    mert.clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    f[1]=1;
    mert[0]=INF;
    mert[1]=a[1];
    int res=1;
    for(int i=2;i<=n;i++){
        int mid,L=1,R=res+1,ans=1;
        while(L<=R){
            mid=(L+R)>>1;
            if(check(mid,a[i])){
                ans=mid;
                L=mid+1;
            }
            else R=mid-1;
        }
        if(!mert.count(ans))mert[ans]=a[i];
        else mert[ans]=max(mert[ans],a[i]);
        f[i]=ans;
        res=max(res,ans);
    }
    printf("%d\n",res);
    return 0;
}
