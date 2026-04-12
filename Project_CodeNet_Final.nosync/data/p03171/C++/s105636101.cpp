#include <bits/stdc++.h>
#define db(x) cout<<x<<" "
#define db1(x) cout<<x<<'\n'
#define db2(x,y) cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pair(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ll  long long int
#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define mod 1000000007
#define MAX_N 100000
using namespace std;
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
ll dp[3001][3001];
ll score(vector<ll>&arr,int i,int j, int type){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(type){
        ll op1 = arr[i] + score(arr,i+1,j,1-type);
        ll op2 = arr[j] + score(arr,i,j-1,1-type);
        return dp[i][j] = max(op1,op2);
    }
    else{
        ll op1 = score(arr,i+1,j,1-type);
        ll op2 = score(arr,i,j-1,1-type);
        return dp[i][j] = min(op1,op2);
    }
    return 0;
}

void solve(){

    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<ll>arr(n);
    ll sum = 0;
    rep(i,n)
    cin>>arr[i],sum+=arr[i];

    ll scoreX = score(arr,0,arr.size()-1,1);
    ll scoreY = sum-scoreX;

    db1(scoreX-scoreY);

}
int main(){ 

int t=1;
//cin>>t;
while(t--){
 solve();
}
  return 0; 
}
