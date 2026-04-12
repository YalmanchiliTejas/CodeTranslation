#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

struct Node{
    vector<ll> par;
};

struct Status{
    bool visited[10];
};

Node node[10];
ll N, M;
ll dfs(ll start, Status status){
    status.visited[start]=true;
    bool existnext=false;
    ll tori=0;
    rep(i, node[start].par.size()){
        if(!status.visited[node[start].par[i]]){
            tori+=dfs(node[start].par[i], status);
            existnext=true;
        }
    }
    bool ok=true;
    rep(i, N){
        if(status.visited[i]==false) ok=false;
    }
    if(!existnext){
        if(ok) tori=1;
        else tori=0;
    }
    return tori;
}



int main(void){
    cin>>N>>M;
    rep(i, M){
        ll a, b;
        cin>>a>>b;
        node[a-1].par.push_back(b-1);
        node[b-1].par.push_back(a-1);
    }
    Status fi;
    rep(i, N){
        fi.visited[i]=false;
    }
    cout<<dfs(0, fi)<<endl;
    return 0;
}
