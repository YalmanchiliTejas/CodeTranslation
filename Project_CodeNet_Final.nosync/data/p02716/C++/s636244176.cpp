#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const int N=5e5+5;
struct cs{
    Ll v;int id;
    bool operator <(const cs &a)const {return v<a.v;}
}t;
priority_queue<cs>Q;
Ll a[N],ans;
int l[N],r[N];
bool ok[N];
int n,m;
int main()
{
    scanf("%d",&n);m=n/2;
    for(int i=1;i<=n;i++){
        scanf("%lld",&t.v);
        a[i]=t.v;
        t.id=i;
        l[i]=i-1;
        r[i]=i+1;
        Q.push(t);
    }
    r[0]=1;l[n+1]=n;
    a[n+1]=a[0]=-1e14;
    while(m--){
        while(ok[Q.top().id])Q.pop();
        t=Q.top();Q.pop();
        ans+=t.v;
        int x=t.id;
        a[x]=a[l[x]]+a[r[x]]-a[x];
        t.v=a[x];
        ok[l[x]]=ok[r[x]]=1;
        l[x]=l[l[x]];r[l[x]]=x;
        r[x]=r[r[x]];l[r[x]]=x;
        Q.push(t);
    }
    printf("%lld",ans);
}
