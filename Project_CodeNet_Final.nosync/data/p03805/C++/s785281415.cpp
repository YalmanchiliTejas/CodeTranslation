#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
ll INF=9210000000000000000;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<bool>>path(n,vector<bool>(n,false));
    int x,y;
    rep(i,m){
        cin>>x>>y;x--;y--;
        path[x][y]=true;
        path[y][x]=true;
    }
    vector<int>v(n-1);rep(i,n-1)v[i]=i+1;
    int count=0;
    do{
        bool judge=true;
        judge&=path[0][v[0]];
        rep(i,n-2)judge&=path[v[i]][v[i+1]];
        if(judge)count++;
    }while(next_permutation(all(v)));
    cout<<count;
}