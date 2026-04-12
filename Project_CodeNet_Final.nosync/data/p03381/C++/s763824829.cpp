#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200005],b[200005];
int main(){
    int n;
    scanf("%d",&n);
    b[0]=-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]<=b[n/2]) printf("%d\n",b[n/2+1]);
        else printf("%d\n",b[n/2]);
    }

}
