#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int MAX_V = 10;
    int V,E;
    cin>>V>>E;
    vector<vector<int>> es(MAX_V,vector<int>(MAX_V,0));
    rep(i,E){
        int a,b; cin>>a>>b;
        --a; --b;
        es[a][b] = 1;
        es[b][a] = 1;
    }
    int ans = 0;
    vector<int> per(V-1); int cnt=0;
    REP(i,V-1)per[cnt++] = i;
    do{
        int now = 0;
        rep(i,V-1){
            int next = per[i];
            if(es[now][next]){if(i==V-2)ans++;}
            else break;
            now = next;
        }
    }while(next_permutation(per.begin(),per.end()));
    cout<<ans<<endl; return 0;
}
