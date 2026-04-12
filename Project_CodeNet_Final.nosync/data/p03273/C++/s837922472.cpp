#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
using ll = long long;
const ll mod = 1000000007;
const ll INF = 100000000000000000LL;
signed main(){
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    rep(i,h)cin>>a[i];
    vector<bool> r(h,false), c(w,false);
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                r[i]=true;
                c[j]=true;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(r[i]&&c[j])cout<<a[i][j];
        }
        cout<<endl;
    }
}