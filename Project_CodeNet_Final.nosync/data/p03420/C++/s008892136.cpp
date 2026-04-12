#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll n,k,ans=0;
    cin>>n>>k;
    for (ll i = k+1; i <= n; i++)
    {
        ans+=(n/i)*(i-k);
        ans+=max(0LL,(n%i)-max(0LL,k-1LL));
        //cout<< i<<"\t"<<(n/i)*(i-k)<<"\t"<< (n%i)-k+1<<endl;
    }
    
    cout<<ans<<endl;

    return 0;
}