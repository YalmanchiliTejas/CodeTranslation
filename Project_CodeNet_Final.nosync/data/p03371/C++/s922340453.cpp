#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

main()
{
    int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    int ans=0;
    while(x>0&&y>0)
    {
        ans+=min(a+b,c*2);
        x--;
        y--;
    }
    while(x>0)
    {
        ans+=min(a,2*c);
        x--;
    }
    while(y>0)
    {
        ans+=min(b,2*c);
        y--;
    }

    cout<<ans<<endl;
}