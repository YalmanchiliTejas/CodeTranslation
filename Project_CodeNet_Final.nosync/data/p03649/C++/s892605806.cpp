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

    int ans=0;
    while(true){
        int latte=0;
        rep(i,N){
            if(A[i]<N)continue;
            int tmp=A[i]-(N-1);
            tmp=(tmp+N)/(N+1);
            latte+=tmp;
            A[i]-=tmp*(N+1);
        }
        if(latte==0)break;
        rep(i,N)A[i]+=latte;
        ans+=latte;
    }

    cout<<ans<<endl;
    return 0;
}
