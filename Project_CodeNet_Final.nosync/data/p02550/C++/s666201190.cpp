#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vec vector
typedef long long ll;
typedef pair<ll,ll> P;
//const ll big=998244353;
const ll big=1000000007LL;
const ll INF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
    if(x>y)return x;
    else return y;
}
ll min(ll x,ll y){
    if(x<y)return x;
    else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/
    
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll> ans;//余りはたかだかm通り
    set<ll> al;
    int zero=-1;
    int back=-1;
    rep(i,m+1){
        if(al.count(x)){
            rep(j,ans.size())if(x==ans[j]){back=j;break;}
            break;
        }
        al.insert(x);
        ans.emplace_back(x);
        x*=x;x%=m;
        if(x==0){
            zero=i;
            break;
        }
    }
    ll roopsize=ans.size()-back;
    ll res=0;
    if(x==0){
        rep(i,min((int)ans.size(),n))res+=ans[i];
        cout << res << endl;return 0;
    }

    if((int)ans.size()>=n){
        rep(i,n)res+=ans[i];
        cout << res << endl;return 0;
    }
    rep(i,back)res+=ans[i];
    n-=back;
    rep2(i,back,ans.size()){
        ll num=n/roopsize;
        res+=ans[i]*num;
        if(n%roopsize + back>=i+1)res+=ans[i];
    }
    cout << res << endl;
}