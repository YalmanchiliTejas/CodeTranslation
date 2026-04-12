#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
int n,a[max_n];
int s[max_n];
int ans[max_n];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    s[n+1]=n+1;
    for(int i=n;i>=1;i--){
        if((n-i)%2==0)s[i]=s[i+1]-i;
        else s[i]=s[i+1]+i;
    }
    for(int i=1;i<=n;i++)ans[s[i]]=a[i];
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}