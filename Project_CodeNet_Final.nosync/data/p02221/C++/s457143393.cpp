#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

int n,m;
string s;
vector<int> p;
vector<int> ans;

int win(int a,int b){
    int d=abs(a-b);
    if(s[d-1]=='1') return max(a,b);
    else return min(a,b);
}

void solve(int pos,int k,vector<int> v){
    int len=(int)v.size();
    if(v.size()==1){
        ans[pos]=v[0];
        return ;
    }
    vector<int> l,r;
    // l
    {
        rep(i,v.size()/2){
            l.push_back(win(v[2*i],v[2*i+1]));
        }
    }
    {
        rep(i,v.size()/2){
            r.push_back(win(v[(2*i+1)%len],v[(2*i+2)%len]));
        }
    }

    solve(pos,k+1,l);
    solve(pos+(1<<k),k+1,r);
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    int m=(1<<n);
    cin>>s;
    p.resize(m);ans.resize(m);
    rep(i,m) cin>>p[i];
    solve(0,0,p);
    rep(i,m) cout<<ans[i]<<endl;
    return 0;
}

