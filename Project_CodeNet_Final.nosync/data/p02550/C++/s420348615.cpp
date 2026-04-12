#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int INF=1e5+5;
long long n,x,m,ans,sum;
bool vis[INF];
vector<long long> v;
signed main()
{
        scanf("%lld %lld %lld",&n,&x,&m);
        for (int i=1; i<=n; i++) {
                // cout<<i<<" "<<x<<endl;
                v.push_back(x%m); sum++;
                x=(x*x)%m;
                // cout<<i<<" "<<x<<endl;
                if (vis[x]) break;
                vis[x]=true;
        } int flag=0,len=v.size();
        for (int i=0; i<len; i++) {if ((long long)v[i]==x) {flag=i; break;}}
        for (int i=flag; i<len; i++)
                ans+=v[i];
        ans=ans*((n-flag)/(len-flag));
        n=(n-flag)%(len-flag)+flag;
        for (int i=0; i<n; i++) ans+=v[i];
        cout<<ans<<"\n";
        return 0;
}
