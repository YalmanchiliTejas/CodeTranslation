#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N;cin>>N;
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    sort(A.rbegin(),A.rend());
    int d=N/2;
  	if(N%2==0)--d;
    int ans=0;
    REP(i,N){
        if(i<d)ans+=A[i]*2;
        if((i==d||i==d+1)&&N%2==1)ans-=A[i];
      	if(i==d&&N%2==0)ans+=A[i];
        if(i==d+1&&N%2==0)ans-=A[i];
        if(i>d+1)ans-=A[i]*2;
    }
  	int bans=0;
  	sort(A.begin(),A.end());
  	REP(i,N){
        if(i<d)bans+=A[i]*2;
        if((i==d||i==d+1)&&N%2==1)bans-=A[i];
      	if(i==d&&N%2==0)bans+=A[i];
        if(i==d+1&&N%2==0)bans-=A[i];
        if(i>d+1)bans-=A[i]*2;
    }
  	ans=max(ans,bans*(-1));
    cout<<ans<<endl;
}