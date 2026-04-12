#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll a,b,c,x,y,ans=0,n,m,p,q;
    cin>>a>>b>>c>>x>>y;
    ll d=a+b;
    ll e=min(x,y);
    x-=e;
    y-=e;
    n=d*e;
    m=c*e*2;
    if(n<m)
        ans+=n;
    else
        ans+=m;
    if(x){
        if(a*x<c*2*x)
            ans+=a*x;
        else
            ans+=(c*2*x);
    }
    if(y){
        if(y*b<c*2*y)
            ans+=y*b;
        else
            ans+=(c*2*y);
    }
    cout<<ans<<endl;


    return 0;
}
