#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<55)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

//dp[i][j],i1回飛ばしたか? 2回飛ばしたか?
lli dp[3][200200];
bool vis[3][200200];

lli n;
vector<lli> a;

lli func(lli left,lli now){
    if(DEBUG)cout<<"left="<<left<<"now="<<now<<endl;
    if(now>=n){
        if(left>0)return -INF;
        else return 0;
    }
    if(vis[left][now])return dp[left][now];
    vis[left][now]=true;
    lli rtn = -INF;
    rtn = max(rtn,a[now]+func(left,now+2));
    if(left>0)rtn = max(rtn,func(left-1,now+1));

    return dp[left][now] = rtn;
}

int main(){
    // cout << fixed << setprecision(5);
    cin>>n;
    a.resize(n);
    REP(i,0,n)cin>>a[i];

    REP(i,0,3)REP(j,0,200200)dp[i][j]= (-INF);

    if(n==2){
        cout<<max(a[0],a[1])<<endl;
        return 0;
    }
    if(n==3){
        cout<<max({a[0],a[1],a[2]})<<endl;
        return 0;
    }

    lli left;
    if(n%2==0)left=1;
    else left=2;

    cout<<func(left,0)<<endl;
    return 0;
}
