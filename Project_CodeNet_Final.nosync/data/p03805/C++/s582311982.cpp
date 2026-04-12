#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
#define F first
#define S second
#define MK make_pair
const ll E=1e17+7;
const ll MOD=1000000007;

ll n;

vector<vector<ll>> e(100);

ll dfs(ll w,set<ll> done){
    if(done.size()==n-1){return 1;}
    ll count=0;
    done.insert(w);
    for(int i=0;i<e[w].size();i++){
        if(done.find(e[w][i])==done.end()){
            count+=dfs(e[w][i],done);
        }
    }
    return count;
}



int main(){
    ll m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll f,t;
        cin>>f>>t;
        f--; t--;
        e[f].push_back(t);
        e[t].push_back(f);
    }
    set<ll> a;
    cout<<dfs(0,a)<<endl;
    
    
    return 0;
}
