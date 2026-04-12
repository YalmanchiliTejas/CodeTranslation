#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
vector<string> s;
bool visited[10][10];
   int h,w;
bool dfs(int y,int x){
    for(int i=0;i<2;i++){
        int ny,nx;
        if(i==0){ny=y-1;nx=x;}
        else { ny=y;nx=x-1;}
        if(ny<0||nx<0)continue;
        if(visited[ny][nx])return false;
    }
    visited[y][x]=false;
    for(int i=0;i<2;i++){
        int ny,nx;
        if(i==0){ny=y+1;nx=x;}
        else {ny=y;nx=x+1;}
        if(ny>=h||nx>=w||s.at(ny).at(nx)=='.')continue;
        return dfs(ny,nx);
    }
    if(y!=h-1||x!=w-1)return false;
    return true;
}

int main(){
    cin>>h>>w;
    s.resize(h);
    for(int i=0;i<h;i++)cin>>s.at(i);
for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(s.at(i).at(j)=='#')visited[i][j]=true;
    if(dfs(0,0)){
        for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(visited[i][j]){cout<<"Impossible"<<endl;return 0;}
        cout<<"Possible"<<endl;
    }
    else cout<<"Impossible"<<endl;
}
