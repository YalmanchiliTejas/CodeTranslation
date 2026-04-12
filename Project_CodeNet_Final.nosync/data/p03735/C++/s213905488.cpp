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

const int INF=INT_MAX-1;
int N;
int X[222222],Y[222222];

int acc[555555];
signed main(){
    cin>>N;
    rep(i,N)cin>>X[i]>>Y[i];
    rep(i,N)if(X[i]>Y[i])swap(X[i],Y[i]);

    int latte=*max_element(X,X+N)-*min_element(X,X+N);
    int malta=*max_element(Y,Y+N)-*min_element(Y,Y+N);

    int ans=latte*malta;
    vint lis;
    rep(i,N){
        lis.pb(X[i]);
        lis.pb(Y[i]);
    }
    sort(all(lis));lis.erase(unique(all(lis)),lis.end());

    latte=max(*max_element(X,X+N),*max_element(Y,Y+N));
    malta=min(*min_element(X,X+N),*min_element(Y,Y+N));

    rep(i,N){
        int x=lower_bound(all(lis),X[i]+1)-lis.begin();
        int y=lower_bound(all(lis),Y[i]+1)-lis.begin();
        chmax(acc[0],X[i]);
        chmax(acc[x],Y[i]);
        chmax(acc[y],INF);
    }
    rep(i,lis.size())chmax(acc[i+1],acc[i]);
    rep(i,lis.size())chmin(ans,(acc[i]-lis[i])*(latte-malta));
    cout<<ans<<endl;
    return 0;
}
