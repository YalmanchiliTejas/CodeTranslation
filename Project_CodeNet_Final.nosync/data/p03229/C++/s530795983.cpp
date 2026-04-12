#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    sort(ToEnd(A));

    int64_t ans=A.back()-A.front();
    int idx1=N/2-(N%2==0),idx2=N/2;

    rep(n,0,N/2-(N%2==0)){
        cerr<<idx1-n-1<<" "<<idx2+n+1<<endl;
        ans+=abs(A.at(idx1-n-1)-A.at(idx2+n));
        ans+=abs(A.at(idx1-n)-A.at(idx2+n+1));
    }
    if(N%2) ans-=min(abs(A.at(idx1-1)-A.at(idx2)),abs(A.at(idx1)-A.at(idx2+1)));

    cout<<ans<<endl;
}