#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
 
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
const int MAXN=1e5+15;
const ll INF=0x3f3f3f3f;
 
typedef pair<ll,ll>PA;
 
inline ll qpow(ll x,ll n){ll res=1;for(;n;n>>=1){if(n&1)res=(res*x);x=(x*x);}return res;}
pair<ll,ll>P;
vector<PA> V;
multiset<ll>R,B;
int cmp(PA a,PA b)
{
    return a.first<b.first;
}
int main()
{
    int n;
    ll x,y;
    ll res2,ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        V.push_back(make_pair(min(x,y),max(x,y)));
        R.insert(min(x,y));
        B.insert(max(x,y));
    }
    ll maR=-INF,maB=-INF;
    ll miR=INF,miB=INF;
    int col_max=0,col_min=0;
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++)
    {
        maR=max(V[i].first,maR);
        maB=max(V[i].second,maB);
        miR=min(V[i].first,miR);
        miB=min(V[i].second,miB);
    }
 
    ans=(maR-miR)*(maB-miB);
    for(int i=0;i<V.size();i++)
    {
        R.erase(R.find(V[i].first));
        B.insert(V[i].first);
        B.erase(B.find(V[i].second));
        R.insert(V[i].second);
        ans= min (ans,( *R.rbegin()-*R.begin() )*( *B.rbegin()-*B.begin()) );
    }
    cout<<ans<<endl;
    return 0;
}