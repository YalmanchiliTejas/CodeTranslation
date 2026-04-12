//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=0; cin>>n>>k;
    for(int b=k+1;b<=n;b++){
        ans+=(n/b)*(b-k);
        int r=n%b;
        if(r>=k) ans+=r-max(k,1LL)+1;
    }
    cout<<ans<<endl;
}