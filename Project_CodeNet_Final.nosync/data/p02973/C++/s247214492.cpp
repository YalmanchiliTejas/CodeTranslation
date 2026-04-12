#include"bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define MX 100005
#define ll long long
#define INF 1000000005
using namespace std;

int main(){
    int n,a,col[MX],ans=0;
    cin>>n>>a;
    fill(col,col+n,1);
    col[0]=-a;
    rep(i,n-1){
        cin>>a;
        *upper_bound(col,col+n,-a)=-a;
    }
    ans=lower_bound(col,col+n,1)-col;
    cout<<ans<<endl;
    return 0;
}