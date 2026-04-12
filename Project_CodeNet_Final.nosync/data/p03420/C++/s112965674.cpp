#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void READ()
{
#define R READ();
#define INFI 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define mem0(x) memset(x,0,sizeof(x))
#define prln(x) cout<<#x<<"="<<x<<endl;
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
#endif
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(11);
}
///////////////////////////
const int N=5+    1e6;

long long  n,k,ans,ans1,ans2,num;
int main()
{
    
    cin>>n>>k;
    if(k==0){cout<<n*n;return 0;}
    for(int b=k+1;b<=n;b++)
    {
       // prln(b);
        num=(n+1)/b;
        ans1=(b-k)*(num);
        ans2=max(0ll,n+1-(k+(num)*b));
        ans+=ans1+ans2;
       // prln(ans1);prln(ans2);
    }
    cout<<ans;

    return 0;
}

