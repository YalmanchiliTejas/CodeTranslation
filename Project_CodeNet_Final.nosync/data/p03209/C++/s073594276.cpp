#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define F first
#define S second
#define INF 1000000000000000000
#define M 1000000007
void YES(bool o){
    if(o)printf("YES\n");
    else printf("NO\n");
}
void Yes(bool o){
    if(o)printf("Yes\n");
    else printf("No\n");
}
ll ans,n,x,p[55],a[55];
void dfs(ll l,ll y){
    if(y==0)return;
    if(a[l]<=y){
        ans+=p[l];
        return;
    }
    if(l==0)return;
    if(a[l-1]+2<=y){
        ans+=p[l-1]+1;
        y-=(a[l-1]+2);
        dfs(l-1,y);
        return;
    }
    dfs(l-1,y-1);
}
int main(void){
    cin>>n>>x;
    p[0]=1,a[0]=1;
    for(int i=1;i<=50;i++)p[i]=p[i-1]*2+1;
    for(int i=1;i<=50;i++)a[i]=a[i-1]*2+3;
    dfs(n,x);
    cout<<ans<<endl;
}
