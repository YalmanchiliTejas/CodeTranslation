#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define eb emplace_back
#define vi vector<int>
#define pr pair<int,int>
#define endl "\n"
#define sz(x) (int)(x).size()
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
#define all(c) (c).begin(), (c).end()

#define FOR(i,b) for (int i = 0; i < (b); i++)
#define FORR(i,a,b) for (int i = a; i < (b); i++)
#define FORB(i,b) for (int i = (b); i >= (0); i--)
#define FORRB(i,a,b) for (int i = (a);i>= (b); i--)
#define MAXN 3010
const int MOD =  10000007; //1e9 + 7

using namespace std;

int n,arr[MAXN];
ll dp[MAXN][MAXN][2];
bool visited[MAXN][MAXN][2];
ll solve(int i,int j,int flag){
    if(i > j) return 0;
    bool &vis = visited[i][j][flag];
    ll &res = dp[i][j][flag];
    if(vis) return res;
    vis = true;
    if(flag == 1){
        if(i == j ) res = arr[i] + solve(i+1,j,0);
        else{
            res = max(arr[i] + solve(i+1,j,0) , arr[j] + solve(i,j-1,0));
        }
    }
    else {
        if(i == j) res = -arr[i] + solve(i+1,j,1);
        else res = min(-arr[i] + solve(i+1,j,1), -arr[j] + solve(i,j-1,1));
    }
    return res ;
}
int main(){
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("addin.txt","r",stdin);
    //freopen("addout.txt","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout<<solve(0,n-1,1)<<endl;
    
    return 0;
}