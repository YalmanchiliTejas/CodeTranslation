#include<bits/stdc++.h>

#define rep(i,start,n) for(int i=start;i<(int)(n);i++)
#define rrep(i,n,end) for(int i=n-1;i>=end;i--)
#define each(it,v) for(auto it : v)
#define all(v) (v).begin(),(v).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using vpii = vector<Pii>;
using vpll = vector<Pll>;

const ll mod=1e9+7;
const int intINF=INT_MAX;
const ll  longINF=LONG_LONG_MAX;

main()
{
        int a,b,c; cin>>a>>b>>c;
        if((b*10+c)%4==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}