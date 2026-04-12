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

    int ans=0;
    if(2*C>A+B) ans=A*X+B*Y;
    else{
        ans=2*C*min(X,Y);
        if(X>Y) ans+=min(2*C,A)*(X-Y);
        else ans+=min(2*C,B)*(Y-X);
    }
    cout<<ans<<endl;
}
