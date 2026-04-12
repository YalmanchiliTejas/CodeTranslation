#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> > v(n);
    ll ans=0;
    ll a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    queue<pair<ll,set<ll> > > q;
    set<ll> s;
    s.insert(0);
    ll maki,f;
    q.push(make_pair(0,s));
    while(!q.empty()){
        f=q.front().first;
        s=q.front().second;
        q.pop();
        //cout << s.size()<<endl;
        if(s.size()==n){
            ans++;
        }
        else{
            maki=v[f].size();
            for(int i=0;i<maki;i++){
                if(s.find(v[f][i])==s.end()){
                    s.insert(v[f][i]);
                    q.push(make_pair(v[f][i],s));
                    s.erase(v[f][i]);
                }
            }
        }
    }
    cout << ans<<endl;
    return 0;
}
