#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<ull> ulvec;
typedef vector<double> dvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<tuple<ll,ll,ll>> tvec;
typedef vector<string> svec;

int main(){
    int n,m,ans=0;
    cin>>n>>m;
    Graph G(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vec v(n);
    rep(i,n) v[i]=i;
    do{
        if(v[0]==0){
            bool ok=true;
            for(int i=0;i<n-1;i++){
                bool ok1=false;
                for(auto u:G[v[i]]){
                    if(u==v[i+1]) ok1=true;
                }
                if(!ok1){
                    ok=false;
                    break;
                }
            }
            if(ok)ans++;
        }
    }while(next_permutation(all(v)));
    cout<<ans<<endl;
}