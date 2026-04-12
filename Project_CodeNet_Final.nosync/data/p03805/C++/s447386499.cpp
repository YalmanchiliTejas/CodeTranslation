#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define mod 1000000007
#define show(n) cerr<<#n<<" = "<<n<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl

//ここからAtCoder向けdefine
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pint = pair<int,int>;

const int INF = (1 << 30);

const int maxn=8,maxm=28;
int n,m;
vi vec[maxn];
ll ans;

void dfs(int a,set<int> s){
    //show(a);
    //shows(s);
    //show(ans);
    set<int> nx;
    rep(i,vec[a].size()){
        int next=vec[a][i];
        if(s.find(next) ==s.end()){
            nx=s;
            nx.insert(next);
            dfs(next,nx);
        }
    }
    if(s.size()==n){ ans++;/*cerr<<"ans++"<<endl;*/}
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    int a,b;
    rep(i,m){
        cin>>a>>b;
        a--;b--;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    ans=0;
    set<int> s;
    s.insert(0);
    dfs(0,s);
    cout<<ans<<endl;
    return 0;
}