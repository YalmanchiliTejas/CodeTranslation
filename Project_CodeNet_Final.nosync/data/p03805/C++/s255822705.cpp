#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
int n,m;
vector<vector<int>> graph;
int dfs(int now,vector<bool> &visited){
    int res=0;
    bool alvisited=true;
    for(int i=0;i<n;i++)if(!visited.at(i))alvisited=false;
    if(alvisited)return 1;
    for(int i=0;i<graph.at(now).size();i++){
        if(visited.at(graph.at(now).at(i)))continue;
        visited.at(graph.at(now).at(i))=true;
        res+=dfs(graph.at(now).at(i),visited);
        visited.at(graph.at(now).at(i))=false;
    }
    return res;
}
int main(){
cin>>n>>m;
vector<bool> visited(8,false);
graph.resize(n);
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
}
visited.at(0)=true;
cout<<dfs(0,visited)<<endl;
}