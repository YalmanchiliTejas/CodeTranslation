#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const ll mo = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N, M, S, T;
vector<pii> E[100009];
ll D[2][100009], pat[2][100009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>S>>T;
    S--; T--;
    rep(i,M){
        int u,v,c; cin>>u>>v>>c;
        u--; v--;
        E[u].push_back({v,c});
        E[v].push_back({u,c});
    }
    
    priority_queue<pair<ll,int>> P;
    pat[0][S]=pat[1][T]=1;
    rep(i,N) D[0][i]=D[1][i]=1LL<<60;
    D[0][S]=D[1][T]=0;
    P.push({0,S});
    P.push({0,T+100000});
    
    while(P.size()){
        int cur=P.top().second%100000;
        int id=P.top().second/100000;
        ll co=-P.top().first;
        P.pop();
        if(D[id][cur]!=co) continue;
        for(auto& e:E[cur]){
            if(co+e.second<D[id][e.first]){
                pat[id][e.first]=0;
                D[id][e.first]=co+e.second;
                P.push({-D[id][e.first],id*100000+e.first});
            }
            if(co+e.second==D[id][e.first]) (pat[id][e.first]+=pat[id][cur])%=mo;
        }
    }
    
    ll tot=pat[0][T]*pat[0][T]%mo;
    rep(i,N) if(D[0][i]+D[1][i]==D[0][T]){
        if(D[0][i]==D[1][i]){
            tot+=mo-pat[0][i]*pat[0][i]%mo*pat[1][i]%mo*pat[1][i]%mo;
        }
        if(D[0][i]<D[1][i]){
            for(auto& e:E[i]) if(D[0][e.first]+D[1][e.first]==D[0][T]&&D[0][e.first]>D[1][e.first]&&D[0][e.first]==D[0][i]+e.second){
                tot+=mo-pat[0][i]*pat[0][i]%mo*pat[1][e.first]%mo*pat[1][e.first]%mo;
            }
        }
        tot%=mo;
    }
    cout1(tot);
}
