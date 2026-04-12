#include <bits/stdc++.h>
using namespace std;
int n;
int ans[200010];
struct nu{
    int x,idx;
    bool operator < (const nu & other) const {
        return (x==other.x)?(idx<other.idx):(x<other.x);
    }
} a[200010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].idx = i;
    }
    sort(a+1,a+n+1);
    for(int i=(n/2)+1;i<=n;i++) ans[a[i].idx] = a[n/2].x;
    for(int i=(n/2);i>=1;i--) ans[a[i].idx] = a[n/2+1].x;
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';

    return 0;
}
