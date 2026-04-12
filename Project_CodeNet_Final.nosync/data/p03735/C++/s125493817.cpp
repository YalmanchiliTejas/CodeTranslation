#include<bits/stdc++.h>
using namespace std;
#define maxn 200100
#define ll long long
#define INF 0x3f3f3f3f
#define P pair<int,int>
int x[maxn],y[maxn];
int n;
int mx,id1,mn,id2;
set<P>ss;
int main()
{
    while(~scanf("%d",&n))
    {
        mx=0,mn=INF;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>y[i]) swap(x[i],y[i]);
            if(mx<y[i]) mx=y[i],id1=i;
            if(mn>x[i]) mn=x[i],id2=i;
        }
        ll ans;
        ll tmp1=y[id2],tmp2=x[id1];
        for(int i=1;i<=n;++i)
        {
            tmp1=min(tmp1,(ll)y[i]);
            tmp2=max(tmp2,(ll)x[i]);
        }
        ans=(mx-tmp1)*(tmp2-mn);
        if(id1==id2){cout<<ans<<"\n"; continue;}
        ss.clear();
        ss.insert(P(x[id1],-1)); ss.insert(P(y[id2],-1));
        tmp1=INF;
        for(int i=1;i<=n;++i)
        {
            if(i==id1||i==id2) continue;
            ss.insert(P(x[i],i));
        }
        set<P>::iterator it;
        P tx1,tx2;
        while(true)
        {
            it=ss.begin();
            tx1=*(it);
            it=ss.end();
            it--;
            tx2=*(it);
            tmp1=min(tmp1,(ll)(tx2.first-tx1.first));
            if(tx1.second==-1) break;
            ss.erase(tx1);
            ss.insert(P(y[tx1.second],-1));
        }
        ans=min(ans,tmp1*(mx-mn));
        cout<<ans<<"\n";
    }
    return 0;
}
