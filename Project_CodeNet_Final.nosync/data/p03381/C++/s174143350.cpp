#include<bits/stdc++.h>
using namespace std;
struct A{
    int va,po;
} a[200020];
bool order(A a,A b){
    return a.va<b.va;
}
int ans[200020];
int main()
{
    int n,i,ii;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i].va);
        a[i].po=i;
    }
    sort(a+1,a+n+1,order);
    for(i=1;i<=n;i++){
        ii=a[i].po;
        if(i<=n/2){
            ans[ii]=a[n/2+1].va;
        }
        else{
            ans[ii]=a[n/2].va;
        }
    }
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
