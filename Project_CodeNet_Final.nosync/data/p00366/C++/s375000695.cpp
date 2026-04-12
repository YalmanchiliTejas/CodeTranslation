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

int latte[111111];


signed main(){
    int N;cin>>N;

    vint T(N);rep(i,N)cin>>T[i];

    int m=*max_element(all(T));

    fill_n(latte,111111,INT_MAX);
    for(int i=1;i<=m;i++){
        if(m%i==0)latte[i]=0;
    }
    for(int i=100000;i>0;i--)chmin(latte[i],latte[i+1]+1);

    int ans=0;
    rep(i,N)ans+=latte[T[i]];
    cout<<ans<<endl;
    return 0;
}