#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define _GLIBCXX_DEBUG
const int INF=1e18;

signed main(){
  	int A,B,C,X,Y,ans;cin>>A>>B>>C>>X>>Y;
    if(2*C<A+B){
        ans=min(X,Y)*2*C;
        if(X>Y){
          	if(2*C>A)ans+=A*(X-Y);
          	else ans+=(X-Y)*2*C;
        }
        else{
          	if(2*C>B)ans+=B*(Y-X);
          	else ans+=(Y-X)*2*C;
        }
    }
    else{
        ans=A*X+B*Y;
    }
    cout<<ans<<endl;
}