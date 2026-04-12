#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#include<map>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
int n,m;
ll hoge=0;
vvi d(11,vi(11,INF));
void dfs(int num, int cnt,vb used){
    if(!used[num])return;
    else used[num]=false;
    rep(i,n+1){
        if(used[i])break;
        if(cnt==n-1&&i==n){hoge++; return;}
        
    }
    rep(i,n+1){
        if(i){if(d[num][i]==0&&used[i])dfs(i,cnt+1,used);}
    }
    
}
int main(){
    cin>>n>>m;int cnt=1;
    vb used(100,true); used[1]=false; used[0]=false;
    rep(i,m){int a,b; cin>>a>>b; d[a][b]=0; d[b][a]=0;}
    rep(i,n+1){
        if(d[1][i]==0)dfs(i,cnt,used);
    }
    cout<<hoge<<endl;
}