#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
typedef pair<int,int> P;
#define fi first
#define se second
const ll inf=0x3f3f3f3f3f3f3f3f;
int n;
P p[max_n];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].fi,&p[i].se);
        if(p[i].fi>p[i].se)swap(p[i].fi,p[i].se);
    }
    sort(p+1,p+n+1);
    ll ans=inf;
    ll mx1=inf,mx2=-inf,mx3=inf,mx4=-inf;
    for(int i=1;i<=n;i++){
        mx1=min(mx1,p[i].fi*1ll),mx2=max(mx2,p[i].fi*1ll);
        mx3=min(mx3,p[i].se*1ll),mx4=max(mx4,p[i].se*1ll);
    }
    ans=min(ans,(mx4-mx3)*(mx2-mx1));
    multiset<int> s;
    for(int i=1;i<=n;i++)s.insert(p[i].fi);
    for(int i=1;i<=n;i++){
        int x=*s.begin(),y=*s.rbegin();
        ans=min(ans,(y-x)*(mx4-mx1));
        s.erase(s.find(p[i].fi));
        s.insert(p[i].se);
    }
    int x=*s.begin(),y=*s.rbegin();
    ans=min(ans,(y-x)*(mx4-mx1));
    printf("%lld\n",ans);
    return 0;
}