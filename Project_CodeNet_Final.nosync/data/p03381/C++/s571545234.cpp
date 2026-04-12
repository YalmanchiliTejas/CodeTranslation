#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
pair<int, int> a[200001];
int b[200001];
int main(){
    int n,i,j;
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>a[i].f, a[i].s=i;
    sort(a+1,a+n+1);
    for(i=1; i<=n/2; ++i)
        b[a[i].s]=a[n/2+1].f;
    for(i=n/2+1; i<=n; ++i)
        b[a[i].s]=a[n/2].f;
    for(i=1; i<=n; ++i)
        cout<<b[i]<<"\n";
    return 0;
}
