//http://tutuz.hateblo.jp/entry/2018/07/16/135300
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

ll n,k;
ll solve(){
   ll ans=0;
   for(int b=1;b<=n;b++){
       ans+=max(0ll,b-k)*(n/b)+max(0ll,n%b-k+1);
   }
   if(k==0)ans=n*n;

   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    cout<<solve()<<endl;
    return 0;
}