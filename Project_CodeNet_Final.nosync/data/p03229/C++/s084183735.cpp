#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N;
    cin>>N;
    vint A(N);rep(i,N)cin>>A[i];
    sort(all(A));
    int ans=0;
    rep(i,N/2)ans+=(A[N-1-i]-A[i])*2;
    if(N%2==0)ans+=A[N/2-1]-A[N/2];
    else{
        ans+=max(A[N/2-1]-A[N/2],A[N/2]-A[N/2+1]);
    }
    cout<<ans<<endl;
    return 0;
}
