#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,m,n) for(int i=m;i<(n);i++)
#define ALL(x) x.begin(),x.end()


void solve(){
    int N;cin>>N;
    if(N==0)exit(0);
    vector<int>A(N);
    REP(i,N)cin>>A[i];
    sort(ALL(A));
    int sum = 0;
    FOR(i,1,N-1)sum+=A[i];
    cout<<sum/(N-2)<<endl;
}
signed main(){
    while(true){
        solve();
    }
}
