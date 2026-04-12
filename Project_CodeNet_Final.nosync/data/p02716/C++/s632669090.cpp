#include<bits/stdc++.h>
#define ALL(c) begin(c), end(c)
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;


ll solve(vector<int> a){
    int n = a.size();
    if(n==1) return 0;
    int m = n%2 ? 2 : 1;
    ll inf = 1e18;
    vector<vector<ll>> d(n+2, vector<ll>(m+1,-inf));
    d[n+1][0] = 0;
    d[n][0] = 0;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=m;++j){
            ll res = -inf;
            for(int k=0;k<=j;++k){
                int p = i+k+2;
                if(p<=n+1) res = max(res, a[i] + d[p][j-k]);
            }
            d[i][j] = res;
            //cerr<<res<<' ';
        }//cerr<<endl;
    }
    
    ll ans = -inf;
    for(int k=0;k<=m;++k) if(k<n) ans= max(ans, d[k][m-k]);
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
    
    int n;
    
    cin>>n;
    vector<int> a(n);
    for(auto &_ : a) cin>>_;
    
    
    cout<<solve(a)<<endl;
    
    
    return 0;
}
