#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(ll i=0;i<N;++i)
typedef long long int ll;
const ll INF = 1<<30;

ll N,M;
vector<vector<ll> > Edge;
vector<ll> v;

bool search();

int main(){
    cin >> N >> M;
    Edge.resize(N);
    v.resize(N-1);
    rep(i,M){
        ll a, b; cin >> a >> b;
        a--; b--;
        Edge[a].push_back(b); Edge[b].push_back(a);
    }
    rep(i,N-1) v[i] = i+1;

    ll res = 0;
    if(search()) res++;
    while(next_permutation(v.begin(),v.end())){
        if(search()) res++;
    }
    cout << res << endl;
}

bool search(){
    int now = 0;
    bool ok;
    rep(i,N-1){
        ok = false;
        for(auto it : Edge[now]){
            if(it == v[i]){
                ok = true;
                now = v[i];
                break;
            }
        }
        if(!ok) return false;
    }
    return ok;
}