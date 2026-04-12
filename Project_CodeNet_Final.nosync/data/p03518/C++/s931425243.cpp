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

void run(int k){

    ans.pb(k);
    for(int i=k;i<N;i++)swap(P[i-k],P[i]);


}

signed main(){
    cin>>N;
    rep(i,N)cin>>P[i];
    rep(t,N){
        rep(i,N){
            if(P[0]!=0&&P[0]<P[N-1])run(N-1);
            run(1);
        }
    }

    while(P[0]!=0)run(1);


    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]<<endl;
}
