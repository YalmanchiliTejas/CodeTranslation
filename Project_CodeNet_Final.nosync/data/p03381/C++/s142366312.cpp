#include <bits/stdc++.h>
using namespace std;
int n,k;
int x[200002],y[200002];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&k);
        x[i] = k;
        y[i] = k;
    }
    sort(&x[0],&x[n]);
    int a[2] = {x[(n/2)-1],x[n/2]};
    if (a[0]==a[1]) {
        for (int i=0; i<n; i++) {
            printf("%d\n", a[0]);
        }
    }
    else {
        for (int i=0; i<n; i++) {
            if (y[i]<=a[0]) printf("%d\n",a[1]);
            else printf("%d\n",a[0]);
        }
    }
}
