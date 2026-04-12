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

    int ans;
    if(C>=A+B){
        ans=A*X+B*Y;
    }
    else{
        if(X>=Y){
            ans=C*Y+min(A,C)*(X-Y);
        }
        else{
            ans=C*X+min(B,C)*(Y-X);
        }
    }
    cout<<ans<<endl;

}
