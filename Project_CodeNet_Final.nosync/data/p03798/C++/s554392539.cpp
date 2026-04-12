#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n;string s;cin >> n>>s;
    rep(i,4){
        string a;
        if(i%2==0)a.pb('S');
        else a.pb('W');
        if(i>=2)a.pb('S');
        else a.pb('W');
        rep(j,n-2){
            char x=s[j+1];
            if(x=='o'){
                if(a[j+1]=='S'){
                    a.pb(a[j]);
                }
                else {
                    if(a[j]=='S')a.pb('W');
                    else a.pb('S');
                }
            }
            if(x=='x'){
                if(a[j+1]=='W'){
                    a.pb(a[j]);
                }
                else {
                    if(a[j]=='S')a.pb('W');
                    else a.pb('S');
                }
            }
        }
        bool b=false;
        if(s[0]=='o'){
            if(a[0]=='S'){
                if(a[n-1]==a[1])b=true;
            }
            else if(a[n-1]!=a[1])b=true;
        }
        if(s[0]=='x'){
            if(a[0]=='S'){
                if(a[n-1]!=a[1])b=true;
            }
            else if(a[n-1]==a[1])b=true;
        }
        bool c=false;
        if(s[n-1]=='o'){
            if(a[n-1]=='S'){
                if(a[n-2]==a[0])c=true;
            }
            else if(a[n-2]!=a[0])c=true;
        }
        if(s[n-1]=='x'){
            if(a[n-1]=='S'){
                if(a[n-2]!=a[0])c=true;
            }
            else if(a[n-2]==a[0])c=true;
        }
        if(c&&b){
            cout <<a <<endl;
            return 0;
        }
    }
    cout << -1 <<endl;
}