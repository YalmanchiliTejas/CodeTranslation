#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int main(){
    int n,m;
    cin>>n>>m;
    int edge[n][n];
    memset(edge,0,sizeof(edge));
    rep(i,m){
        int a,b;
        cin>>a>>b;
        edge[a-1][b-1]=1;
        edge[b-1][a-1]=1;
    }
    vector<int> a(n);
    rep(i,n)a[i]=i;
    int ans=0;
    int combi=1;
    rep(i,1,n)combi*=i;
    rep(i,combi){
        bool flag=1;
        rep(j,n-1){
            if(!edge[a[j]][a[j+1]]){
                flag=0;
                break;
            }
        }
        if(flag)++ans;
        next_permutation(a.begin(),a.end());
    }
    cout<<ans<<endl;
}
