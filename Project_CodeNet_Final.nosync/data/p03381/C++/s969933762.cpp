#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[202020];
int b[202020];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        printf("%d\n", b[n/2] > a[i] ? b[n/2] : b[n/2-1]);
    }

}
