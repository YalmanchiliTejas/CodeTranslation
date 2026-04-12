#include <iostream>
#include <algorithm>
using namespace std;
const int N=200000+10;
int n,a[N],b[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]<=b[n/2]) printf("%d\n", b[n/2+1]);
        else printf("%d\n", b[n/2]);
    }
}