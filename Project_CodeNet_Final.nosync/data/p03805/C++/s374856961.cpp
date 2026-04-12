#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
vector<int>edge[10];
bool seen[8];
int dfs(int s,int n,bool seen[8]){
    bool ful =true;
    rep(i,n){
        if(!seen[i])ful=false;
    }
    if(ful)return 1;
    int sum =0;
    for(int ne:edge[s]){
        if(seen[ne])continue;
        seen[ne]=true;
        sum +=dfs(ne,n, seen);
        seen[ne]=false;
    }
    return sum;
}
int main(){
   int n,m;cin>>n>>m;
   rep(i,m){
       int a,b;
       cin>>a>>b;
       a--;b--;
       edge[a].push_back(b);
       edge[b].push_back(a);
   }
   bool seen[n];
   rep(i,n)seen[i]=false;
   seen[0]=true;
   cout<<dfs(0,n,seen)<<endl;
}