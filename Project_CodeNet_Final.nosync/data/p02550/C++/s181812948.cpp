#include <bits/stdc++.h>
#define NMAX 100005
#define MOD 998244353

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll lastpos[NMAX];
vector<ll> v;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,x,m,s=0,i=1;
    cin>>n>>x>>m;
    while(i<=n && lastpos[x]==0){
        lastpos[x]=i++;
        v.push_back(x);
        s+=x;
        x=x*x%m;
    }
    v.push_back(x);
    if(i>n){
        cout<<s;
        return 0;
    }
    n-=v.size()-1;
    ll s2=0,cycleSize=0;
    for(ll j=lastpos[x];j<v.size();j++){
        s2+=v[j];
        cycleSize++;
    }
    s+=n/cycleSize*s2;
    n%=cycleSize;
    while(n--){
        s+=x;
        x=x*x%m;
    }
    cout<<s;
    return 0;
}
