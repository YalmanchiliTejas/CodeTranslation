#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define fr(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define mod 1000000007
#define fr(i, a, b) for (int i = a; i < b; i++)
#define fast_io ios::sync_with_stdio(false);cin.tie(0);
ll dp[3001][3001][2];
ll solve(vi &a,int i,int j,bool turn){
    if(i>j){
        return 0;
    }
    if(dp[i][j][turn]!=-1) return dp[i][j][turn];
    if(turn==1){
        return dp[i][j][1]=max(a[i] + solve(a,i+1,j,0),a[j] + solve(a,i,j-1,0));
    } else{
         return dp[i][j][0]=min(solve(a,i+1,j,1),solve(a,i,j-1,1));        
    }
}
int main(){
    fast_io
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;cin>>n;
    vi a(n+1);
    ll sum=0;
    fr(i,1,n+1) {
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof dp);
    ll x = solve(a,1,n,1);
    ll y = sum-x;
    cout<<x-y<<endl;
    return 0;
}