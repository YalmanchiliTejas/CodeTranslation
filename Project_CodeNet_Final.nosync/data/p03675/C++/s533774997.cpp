#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int b[200005];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=(1+n)/2,r=(1+n)/2,tot=1;
    if (!(n%2)) l++,r++;
    b[l]=a[1];
    while (tot<n) {
        b[--l]=a[++tot];
        if (tot>=n) break;
        b[++r]=a[++tot];
    }
    if (!(n%2))
    for (int i=1;i<=n;i++)
        cout<<b[i]<<" ";
    else for (int i=n;i>=1;i--) cout<<b[i]<<" ";
    return 0;
}
