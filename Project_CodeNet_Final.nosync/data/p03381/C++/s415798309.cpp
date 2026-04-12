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
int ans[222222];
signed main(){
    cin>>N;
    vpint latte;
    rep(i,N){
        int a;cin>>a;
        latte.pb({a,i});
    }
    sort(all(latte));
    rep(i,latte.size()){
        if(i<N/2){
            ans[latte[i].se]=latte[N/2].fi;
        }
        else{
            ans[latte[i].se]=latte[N/2-1].fi;
        }
    }
    rep(i,N)cout<<ans[i]<<endl;
    return 0;
}
