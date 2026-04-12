#include <iostream>
using namespace std;
long long i,n,a[3009],d[3009][3009];
bool b[3009][3009];
long long dp(int l,int r){
    if(l==r) return d[l][r]=a[l];
    if(b[l][r]) return d[l][r];
    b[l][r]=1;
    d[l][r]=max(a[l]-dp(l+1,r),a[r]-dp(l,r-1));
    return d[l][r];
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    cout<<dp(0,n-1);
    return 0;
}
