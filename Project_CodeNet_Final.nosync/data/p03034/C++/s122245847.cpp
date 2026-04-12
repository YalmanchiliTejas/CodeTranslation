#include <bits/stdc++.h>
using namespace std;
int n,a[100001],x[100001];
long long ans;
int main() {
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=1; i<n-1; i++) { //i is jump length (a-b)
        long long cur=0;
        int l=0,r=n-1;
        while (l!=r and i<r and l<n-1 and x[r]!=i and x[l]!=i) {
            cur+=a[l]; cur+=a[r];
            x[l]=i; x[r]=i;
            l+=i; r-=i;
            ans=max(ans,cur);
        }
    }
    cout<<ans<<'\n';
}
/*
*/