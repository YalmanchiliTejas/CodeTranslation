#include<bits/stdc++.h>
#define ll long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define se second
#define fi first
using namespace std;
const int N=2e5+5;
ll a[N],ans[N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n&1){
        ans[n/2]=a[0];
        int l=n/2-1,r=n/2+1;
        for(int i=1;i<n;i++){
            if(i&1){
                ans[r]=a[i];
                r++;
            }
            else{
                ans[l]=a[i];
                l--;
            }
        }
    }
    else{
        ans[n/2]=a[0];
        int l=n/2-1,r=n/2+1;
        for(int i=1;i<n;i++){
            if(!(i&1)){
                ans[r]=a[i];
                r++;
            }
            else{
                ans[l]=a[i];
                l--;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
