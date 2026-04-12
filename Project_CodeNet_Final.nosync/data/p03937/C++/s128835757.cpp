#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll h,w;cin>>h>>w;
    ll cnt=0;
    rep(i,h*w){
        char c;cin>>c;
        if(c=='#')cnt++;
    }
    if(cnt==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}