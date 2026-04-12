#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x0123456789) cerr<<#x0123456789<<':'<<x0123456789<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x0123456789:v)cerr<<x0123456789<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;
typedef long double ld;

ll N,M,W,T;
vector<ll> V,P;
vector<ll> L,X,Y;
vector<vector<ll>> R,Q;
map<string,ll> m;

ll md(ll x1,ll y1,ll x2,ll y2){
    return abs(x1-x2)+abs(y1-y2);
}

pair<ll,ll> bitfunc(ll n){
    vector<ll> v;
    FOR(i,0,N)if((1<<i)&(n))v.pb(i);
    //x
    ll x=LINF;
    do{
        ll dist=0;
        dist += md(0,0,X[v[0]],Y[v[0]]);
        FOR(i,0,v.size()-1){
            dist += md(X[v[i]],Y[v[i]],X[v[i+1]],Y[v[i+1]]);
        }
        dist += md(X[v[v.size()-1]],Y[v[v.size()-1]],0,0);
        x = min(x,dist);
    }while(next_permutation(ALL(v)));
    //y
    ll value[M],weight[M];
    FOR(i,0,M)value[i]=0,weight[i]=LINF;
    FOR(rep,0,v.size()){
        ll t = v[rep];
        FOR(i,0,L[t]){
           value[R[t][i]] = max(value[R[t][i]],P[R[t][i]]-Q[t][i]);
           weight[R[t][i]] = min(weight[R[t][i]],V[R[t][i]]);
        }
    }
    ll DP[W+1]={0};
    FOR(i,0,M){
        FOR(j,0,W+1){
            if((j == 0 || DP[j]) && j+weight[i]<=W){
                DP[j+weight[i]] = max(DP[j+weight[i]],DP[j]+value[i]);
            }
        }
    }
    ll y=0;
    FOR(i,0,W+1)y = max(y,DP[i]);
    return make_pair(x,y);
}

int main(){
    cin >> N >> M >> W >> T;
    V.resize(M);P.resize(M);
    FOR(i,0,M){
        string s;
        cin >> s >> V[i] >> P[i];
        m[s] = i;
    }
    L.resize(N);X.resize(N);Y.resize(N);
    R.resize(N);Q.resize(N);
    FOR(i,0,N){
        cin >> L[i] >> X[i] >> Y[i];
        FOR(j,0,L[i]){
            string s;
            ll n;
            cin >> s >> n;
            R[i].pb(m[s]);
            Q[i].pb(n);
        }
    }
    ll value[((ll)1<<N)-1],weight[((ll)1<<N)-1];
    FOR(i,1,((ll)1<<N)){
        pair<ll,ll> p = bitfunc(i);
        value[i-1] = p.second;
        weight[i-1] = p.first;
    }
    ll DP[T+1]={0};
    FOR(i,0,((ll)1<<N)-1){
        FOR(j,0,T+1){
            if((j == 0 || DP[j]) && j+weight[i]<=T){
                DP[j+weight[i]] = max(DP[j+weight[i]],DP[j]+value[i]);
            }
        }
    }
    ll ans=0;
    FOR(i,0,T+1)ans = max(ans,DP[i]);
    cout << ans << endl;
}
