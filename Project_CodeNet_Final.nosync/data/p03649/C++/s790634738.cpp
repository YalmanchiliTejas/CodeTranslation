#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[55],p[55];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int cnt;
    LL k=0;
    while(1) {
        cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]<n) cnt++;
        if(cnt==n) break;
        LL sum=0;
        for(int i=1;i<=n;i++) {
            p[i]=a[i]/n;
            sum+=p[i];
        }
        k+=sum;
        for(int i=1;i<=n;i++) {
            a[i]=a[i]-n*p[i]+(sum-p[i]);
        }
    }
    printf("%lld\n",k);
    return 0;
}