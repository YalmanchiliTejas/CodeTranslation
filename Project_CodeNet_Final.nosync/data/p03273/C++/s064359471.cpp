#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll h,w; cin>>h>>w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];

    vector<bool> row(h,false),col(w,false);
    rep(i,h)rep(j,w) if(a[i][j]=='#'){
        row[i]=true;
        col[j]=true;
    }

    rep(i,h){
        if(row[i]){
            rep(j,w){
                if(col[j]){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }

    return 0;
}