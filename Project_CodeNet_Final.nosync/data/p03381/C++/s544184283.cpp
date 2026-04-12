#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n;
void solve(vector<ll>x){
    vector<ll>y=x;
   sort(y.begin(),y.end());
   int l=(n-1)/2;
   int r=n/2;
   rep(i,n){
       if(x[i]<=y[l])cout<<y[r]<<endl;
       else cout<<y[l]<<endl;
   }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    vector<ll>x(n);
    rep(i,n)cin>>x[i];
    solve(x);
    return 0;
}