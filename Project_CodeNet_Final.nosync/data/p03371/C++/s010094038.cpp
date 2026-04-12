#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;

    C*=2;

    int ans=1e18;
    for(int c=0;c<=max(X,Y);c++){
        int a=max(0LL,X-c);
        int b=max(0LL,Y-c);
        int cost=A*a+B*b+C*c;
        ans=min(ans,cost);
    }
    cout<<ans<<endl;

}
