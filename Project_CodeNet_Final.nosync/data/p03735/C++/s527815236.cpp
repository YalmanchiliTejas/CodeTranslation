

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
void read(T &x)
{
    char ch=getchar();
    for (x=0;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
int n;
pair<int,int> x[200010];
multiset<int> b,r;
ll ans;
int main()
{
    read(n);
    for (int i=1;i<=n;i++)
    {
        read(x[i].first),read(x[i].second);
        if (x[i].first>x[i].second) swap(x[i].first,x[i].second);
        b.insert(x[i].first),r.insert(x[i].second);
    }
    ans=1LL*(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin());

    sort(x+1,x+n+1);
    for (int i=1;i<=n;i++)
    {
        b.erase(b.find(x[i].first)),r.insert(x[i].first);
        r.erase(r.find(x[i].second)),b.insert(x[i].second);
        ans=min(ans,1LL*(*b.rbegin()-*b.begin())*(*r.rbegin()-*r.begin()));
    }
    printf("%lld",ans);
    return 0;
}