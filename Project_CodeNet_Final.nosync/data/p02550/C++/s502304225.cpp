#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;

#define _GLIBCXX_DEBUG
#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())

void Add(ll &a, ll b){
    a=(a+b)%mod;
    return;
}

void Pro(ll &a, ll b){
    a=(a*b)%mod;
    return;
}

ll N,X,M; 


ll ruijou(ll n, ll k){
    if(!k) return 1;
    ll a=ruijou(n,k/2);
    a=(a*a)%M;
    return k%2 ? (a*n)%M : a;
}

ll memo[100010];
ll ans[100010];
ll ANS;

void SOLVE(ll i, ll bef){
    if(i>N) return;
    ll A;
    if(i==1) A=X;
    else A=(bef*bef)%M;
    if(!memo[A]) {
        memo[A]=i;
        ans[i]=ans[i-1]+A;
        ANS=ans[i];
        SOLVE(i+1,A);
        return;
    }
    ans[i]=ans[i-1]+A;
    ll p=memo[A];
    ll K=ans[i]-ans[p], F=i-p;
    ll yy=(N-i)/F;
    ANS=ans[i]+(yy*K);
    ll zahyo=i+(F*yy);
    zahyo=N-zahyo;
    ANS+=(ans[zahyo+p]-ans[p]);
    return;
}


ll Solve(){
    cin>>N>>X>>M;
    if(!X) return 0;
    if(N==1) return X;

    SOLVE(1,1);
    return ANS;
    
    
}
int main(){
    cout<<Solve()<<endl;

}