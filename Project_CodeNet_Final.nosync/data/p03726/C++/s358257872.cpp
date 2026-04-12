#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx,avx2")

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define dbg(x) cerr<<#x<<" : "<<x<<endl

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
const ll INF = 1e18+1;
const ll MOD = 1000000007L;
clock_t time_p=clock();
void timer(){time_p=clock()-time_p;cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}

template <typename Arg1> ostream& operator << (ostream& out, const vector<Arg1> &a) {out<<"[ ";for(const auto &x:a)out<<x<<" ";return out<<"]";}

vector<set<ll>>adj;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    adj.assign(n,{});
    rep(i,n-1){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if(n<=3){
        if(n%2==1) cout<<"First\n";
        else cout<<"Second\n";
        exit(0);
    }

    vi white(n,0);
    queue<ll>q;
    vi visited(n,0);
    rep(i,n){
        if(adj[i].size() == 1){ //leaf
            q.push(i);
            visited[i]=1;
        }
    }


    ll ctr = n;
    vi processed(n,0);

    while(!q.empty()){ //leaves
        ll cur = q.front();
        /*
         *for(auto x:adj[cur]) cout<<x<<",";
         *cout<<endl;
         */

        q.pop();
        if(processed[cur] == 1){
            continue;
        }
        if(adj[cur].size() == 0) {
            cout<<"First\n"; exit(0);
        }
        ll par=*adj[cur].begin();
        visited[par]=1;

        processed[par]=1;
        processed[cur]=1;

        vi toRemove;
        for(auto x : adj[par]){
            if(x != cur){
                adj[x].erase(par);
                if(adj[x].size() == 0) {
                    cout<<"First\n"; exit(0);
                }
                if(adj[x].size() == 1){
                    visited[x] = 1;
                    q.push(x);
                }
            }
            toRemove.pb(x);
        }
        adj[cur].erase(par);
        for(auto x:toRemove) adj[par].erase(x);
    }

    cout<<"Second\n";
    exit(0);


    timer();
    return 0;
}
