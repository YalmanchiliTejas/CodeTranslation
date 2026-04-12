#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

long long ruijou(int n, int k){
    if(k==0) return 1;
    int x=k/2;
    long long t=ruijou(n,x);
    
    if(k%2==1) return n*t*t;
    else return t*t;
}

ll N,K;
vec d;

ll solve(ll k, vec D){
    ll ret=0;
    ll n=D.size();
    if(D.size()<k) return 0;
    if(k==1){
        ret=D.at(0);
        ret+=(D.size()-1)*9;
        return ret;
    }

    else{
        if(n>k) {
            ret=1;
            rep(i,k) ret*=(n-1-i);
            rep(i,k) ret/=(i+1);
            rep(i,k) ret*=9;
        }

        vec a,b;
        rep(i,n-1) a.pb(9);
        ret+=(D.at(0)-1)*solve(k-1,a);
        ll x=1;
        while(D.at(x)==0) {x++; if(x==n) break;}
        if(x!=n){
            for(ll i=x; i<n;i++) b.pb(D.at(i));
        }
        ret+=solve(k-1,b);
        return ret;
    }
}


int main(){
    string S; cin>>S;
    N=S.size();
    cin>>K;
    ll ans=1;
    
    rep(i,N) d.pb(S.at(i)-'0');
    
    cout<<solve(K,d)<<endl;
}