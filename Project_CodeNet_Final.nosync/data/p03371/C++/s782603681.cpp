#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){if(a.first==b.first)return a.second<b.second;
return a.first>b.first;}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll a,b,c,x,y,s=INT_MAX;
    cin>>a>>b>>c>>x>>y;
    s=min(s,((ll)(x*a)+(ll)(y*b)));
    s=min(s,(ll)(max(x,y)*2ll*c));
    if(x>y)s=min(s,(ll)((x-y)*a)+(ll)(min(x,y)*2ll*c));
    else s=min(s,(ll)((y-x)*b)+(ll)(min(x,y)*2ll*c));
    cout<<s;

}
