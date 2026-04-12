#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m,w,t;
    cin>>n>>m>>w>>t;
    map<string,int> mp;
    ll v[m],p[m];
    rep(i,m){
        string s;
        cin>>s;
        mp[s]=i;
        cin>>v[i]>>p[i];
    }
    int x[n],y[n];
    vector<pair<int,int>> vec[n];
    rep(i,n){
        int k;
        cin>>k>>x[i]>>y[i];
        rep(j,k){
            string s;
            cin>>s;
            int pp;
            cin>>pp;
            int idx=mp[s];
            pp=p[idx]-pp;
            vec[i].emplace_back(v[idx],pp);
        }
    }
    int all=1<<n;
    ll ti[all], val[all];
    rep(i,all){
        if(i==0){
            ti[i]=val[i]=0;
            continue;
        }
        vector<ll> dp1(3*w);
        vector<int> ord;
        rep(j,n){
            if(((1<<j)&i)==0)continue;
            ord.push_back(j);
            for(auto e : vec[j]){
                rep(l,w+1){
                    dp1[l+e.first]=max(dp1[l+e.first],dp1[l]+e.second);
                }
            }
        }
        int mi=inf;
        do{
            int k=ord.size();
            int d=0;
            rep(l,k-1)d+=abs(x[ord[l+1]]-x[ord[l]])+abs(y[ord[l+1]]-y[ord[l]]);
            d+=abs(x[ord[0]])+abs(y[ord[0]])+abs(x[ord[k-1]])+abs(y[ord[k-1]]);
            mi=min(d,mi);
        }while(next_permutation(ord.begin(), ord.end()));
        ti[i]=mi;
        val[i]=dp1[w];
        
    }
    vector<ll> dp(3*t);
    rep(i,all){
        if(ti[i]>t)continue;
        rep(j,t+1){
            dp[j+ti[i]]=max(dp[j+ti[i]],dp[j]+val[i]);
        }
    }
    cout<<dp[t]<<endl;
    return 0;
}
