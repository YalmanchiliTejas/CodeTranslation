#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define dev 998244353 //tenka1
#define P pair<int,int>
#define F first
#define S second
int n,m,ans=0;
int a[1000],b[1000];
bool flag[10];
vector<int>con[10];
void dfs(int d,int w){
    if(w==n){
        ans++;
        return;
    }
    int l=con[d].size();
    rep(i,l){
        if(flag[con[d][i]]==false){
            flag[con[d][i]]=true;
            dfs(con[d][i],w+1);
            flag[con[d][i]]=false;
        }
    }
    return;
}
signed main(){
    cin>>n>>m;
    rep(i,m){
        cin>>a[i]>>b[i];
        con[a[i]].push_back(b[i]);
        con[b[i]].push_back(a[i]);
    }
    flag[1]=true;
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
