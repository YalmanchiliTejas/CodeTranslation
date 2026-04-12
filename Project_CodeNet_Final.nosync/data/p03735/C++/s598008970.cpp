#include <bits/stdc++.h>
using namespace std;
 
const int inf=1e9;
pair<int,int> v[400010];
vector<int> poz[200010];
 
int main()
{
    int n,max1=0,min1=inf,max2=0,min2=inf,a,b;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d%d",&a,&b);
        v[2 * i - 1] = {a,i};
        v[2 * i] = {b,i};
        if(a < b) swap(a,b);
        max1=max(max1,a);
        min1=min(min1,a);
        max2=max(max2,b);
        min2=min(min2,b);
    }
    long long sol=1LL*(max1-min1)*(max2-min2);
    sort(v+1,v+1+2*n);
    for(int i=1;i<=2*n;i++) poz[v[i].second].push_back(i);
    a=b=2;
    int nr=0;
    for(int i=1;i<=2*n;i++)
    {
        for(;nr<n && b<2*n;b++)
            if(poz[v[b].second][0]==b || poz[v[b].second][0]<a) nr++;
        if(nr<n) break;
        sol=min(sol,1LL*(v[2*n].first-v[1].first)*(v[b-1].first-v[a].first));
        nr--;
        if(poz[v[a].second][0]==a && poz[v[a].second][1]<b) nr++;
        a++;
    }
    printf("%lld",sol);
    return 0;
}
