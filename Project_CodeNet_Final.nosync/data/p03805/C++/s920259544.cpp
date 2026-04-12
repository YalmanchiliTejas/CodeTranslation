#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
vector<vector<int> > v(8);
int ans=0,n,m;
void dfs(int i,set<int> s){
    s.insert(i);
    if(s.size()==n){
        ans++;
        return;
    }
    for(int a:v[i]){
        if(s.find(a)==s.end())dfs(a,s);
    }
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    set<int> c; 
    dfs(0,c);
    cout << ans<<endl;
    return 0;
}
