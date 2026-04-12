#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream f("A.in");
ofstream g("A.out");
typedef long long ll;
typedef pair<int,int> pi;
int t,T;
const ll Mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector < ll > V(n+1),pf(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>V[i];
        pf[i]=(pf[i-1]+V[i])%Mod;
        if(pf[i]<0) pf[i]+=Mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans + ( V[i]*(pf[n]-pf[i]) )%Mod )%Mod;
        if(ans<0) ans+=Mod;
    }
    cout<<ans;

    return 0;
}
