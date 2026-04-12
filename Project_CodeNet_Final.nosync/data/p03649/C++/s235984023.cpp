#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;


vector<int> v[1010];
int a[1010];
pint dfs(int x){
    if(v[x].empty())return {0,a[x]};
    bitset<5050> b=1;
    int sum=0;
    for(auto to:v[x]){
        pint p=dfs(to);
        if(p.first==-1)return {-1,-1};
        b=(b<<p.first|b<<p.second);
        sum+=p.first+p.second;
    }
    for(int i=a[x];i>=0;i--){
        if(b[i])return {a[x],sum-i};
    }
    return {-1,-1};
}

int main(){
    int n;cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0;
    while(1){
        sort(a,a+n);
        reverse(a,a+n);
        if(a[0]<n)break;
        ll pos=a[0]/n;
        ans+=pos;
        a[0]-=pos*n;
        rep(i,n-1)a[i+1]+=pos;
    }
    cout<<ans<<endl;
    return 0;
}