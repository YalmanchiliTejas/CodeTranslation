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

int N;
int P[222];

vint ans;

void s(int k){
    for(int i=k;i<N;i++)swap(P[i],P[i-k]);
    ans.pb(k);
}

signed main(){
    cin>>N;
    rep(i,N)cin>>P[i];


    rep(i,N){
        rep(j,N-1){
            s(1);
            if(P[N-1]>P[0])s(N-1);
        }
        s(1);
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]<<endl;

    return 0;
}
