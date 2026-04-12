#include <bits/stdc++.h>
#define double long double
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;
using vs=vector<string>;
using vd=vector<double>;
using vvd=vector<vd>;
using vb=vector<bool>;
using pll=pair<ll,ll>;
#define all(a) a.begin(),a.end()
#define rep(i,n) range(i,0,n)
#define range(i,a,n) for(ll i=(a);i<n;i++)
#define LINF ((ll)1ll<<60)
#define fcout(a) cout<<setprecision(a)<<fixed
#define EPS (1e-10)

int sgn(const double&r){return (r>EPS)-(r<-EPS);}
int sgn(const double&a, const double&b){return sgn(a-b);}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vl d(m);
    vb isdark(n,false);
    map<ll,ll> assm;
    rep(i,m){cin>>d[i];d[i]--;isdark[d[i]]=true;assm[d[i]]=i;}

    vvl v(n,vl(k));
    rep(i,n)rep(j,k){cin>>v[i][j];v[i][j]--;}
    vb memo(1<<m, false);
    queue<pll> q;
    q.emplace((1<<m)-1, 0);
    while(!q.empty()){
        ll s,c;
        tie(s,c)=q.front();
        q.pop();
        if(memo[s])continue;
        memo[s]=true;
        rep(i,k){
            ll nxt=0;
            rep(j,m){
                if( s & (1<<j)){
                    if(isdark[v[d[j]][i]]){
                        nxt|=(1<<(assm[v[d[j]][i]]));
                    }
                }
            }
            if(!nxt){
                cout<<c+1<<endl;
                return 0;
            }
            if(memo[nxt])continue;
            q.emplace(nxt, c+1);
        }
    }
}
