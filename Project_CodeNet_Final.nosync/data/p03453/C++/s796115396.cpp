#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
const ll MAX=110000;
const ll MOD=1000000007;
priority_queue<plll> tmp;
vector<pll> adj[MAX];
ll n,m,sd[MAX],td[MAX],sr[MAX],tr[MAX],S,T,fin;
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&S,&T);
    for(ll i=0;i<m;i++){
        ll t,t1,t2;
        scanf("%lld%lld%lld",&t1,&t2,&t);
        adj[t1].push_back(make_pair(t2,t));
        adj[t2].push_back(make_pair(t1,t));
    }
    tmp.push(make_pair(-1,make_pair(S,0)));
    while(!tmp.empty()){
        plll t=tmp.top();
        tmp.pop();
        t.first=-t.first;
        if(sd[t.second.first]==0ll){
            sd[t.second.first]=t.first;
            if(t.second.second==0) sr[t.second.first]=1;
            else sr[t.second.first]+=sr[t.second.second],sr[t.second.first]%=MOD;
            for(ll i=0;i<adj[t.second.first].size();i++) if(sd[adj[t.second.first][i].first]==0) {
                tmp.push(make_pair(-t.first-adj[t.second.first][i].second,make_pair(adj[t.second.first][i].first,t.second.first)));
            }
        }
        else if(sd[t.second.first]==t.first){
            sr[t.second.first]+=sr[t.second.second],sr[t.second.first]%=MOD;
        }
    }

    tmp.push(make_pair(-1,make_pair(T,0)));
    while(!tmp.empty()){
        plll t=tmp.top();
        tmp.pop();
        t.first=-t.first;
        if(td[t.second.first]==0ll){
            td[t.second.first]=t.first;
            if(t.second.second==0) tr[t.second.first]=1;
            else tr[t.second.first]+=tr[t.second.second],tr[t.second.first]%=MOD;
            for(ll i=0;i<adj[t.second.first].size();i++) if(td[adj[t.second.first][i].first]==0) {
                tmp.push(make_pair(-t.first-adj[t.second.first][i].second,make_pair(adj[t.second.first][i].first,t.second.first)));
            }
        }
        else if(td[t.second.first]==t.first){
            tr[t.second.first]+=tr[t.second.second],tr[t.second.first]%=MOD;
        }
    }
    for(ll i=1;i<=n;i++) sd[i]--,td[i]--;//printf("%lld %lld\n",sr[i],tr[i]);
    fin=sr[T]*tr[S],fin%=MOD;
    //printf("%lld\n",fin);
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<adj[i].size();j++){
            ll t=adj[i][j].second;
            ll t1=i,t2=adj[i][j].first;
            if(sd[t1]+t+td[t2]==sd[T]) if(sd[t1]*2<sd[T]&&td[t2]*2<sd[T]) fin-=(((sr[t1]*tr[t2])%MOD*sr[t1]%MOD)*tr[t2]%MOD),fin+=MOD,fin%=MOD;
        }
        if(sd[i]+td[i]==sd[T]) if(sd[i]*2==sd[T]) fin-=(((sr[i]*tr[i])%MOD*sr[i])%MOD*tr[i])%MOD,fin+=MOD,fin%=MOD;
    }
    printf("%lld\n",fin);
}
