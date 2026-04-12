#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 100000000

using namespace std;

int main()
{
    //COMinit();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    llong ans=5000000100;
    for(int i=0; i<=max(x,y); i++)
    {
        llong cost=0;
        cost=c*2*i+a*max(0,x-i)+b*max(0,y-i);
        ans=min(ans,cost);
    }
    cout<<ans<<endl;
    return  0;
}