#include<bits/stdc++.h>
using namespace std;
int n;
int a[1009];
bool p[40009];
int x[40009],lx;
long long ans;
bool cmp(int x,int y){return x<y;}
void pd(int x){
    if(x==1) return;
    long long sum=0;
    for(int j=1;j<=n;j++)
        if(a[j]%x==0) sum+=a[j];
    ans=max(ans,sum);
}
int main(){
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
        scanf("%d",&a[j]);
    sort(a+1,a+n+1,cmp);
    for(int j=2;j*j<=a[n];j++){
        if(p[j]==0){
            x[++lx]=j;
            pd(j);
        }
        for(int i=1;i<=lx;i++){
            if(j*x[i]>40000) continue;
            p[j*x[i]]=1;
            if(j%x[i]==0) break;
        }
    }
    for(int j=1;j<=n;j++)
        pd(a[j]);
    printf("%lld\n",ans);
    return 0;
}
