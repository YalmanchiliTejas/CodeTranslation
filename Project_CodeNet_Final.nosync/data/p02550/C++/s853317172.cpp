//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cassert>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define SIZE 100005
#define INF 1e18
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define vec vector
using pint = pair<int,int>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = acos(-1);
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n,x,m;
    cin>>n>>x>>m;
    //idいつ訪れたか
    vll id(m,-1);
    vll a;
    ll len=0;
    ll tot=0;
    while(id[x]==-1){
        a.push_back(x);
        id[x]=len;
        len++;
        x=x*x%m;
    }

    ll loop_sum=0;
    for(int i=id[x];i<len;i++){
        loop_sum+=a[i];
    }

    ll ans=0;
    if(n<=len){
        rep(i,n)ans+=a[i];       
    }else{
        rep(i,id[x])ans+=a[i];
        n-=id[x];
        ans+=loop_sum*(n/(len-id[x]));
        rep(j,n%(len-id[x]))ans+=a[id[x]+j];
    }

    cout<<ans<<endl;
    return 0;
}