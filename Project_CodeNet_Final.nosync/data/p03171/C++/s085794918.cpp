#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<long long int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<ll> >
#define vvi vector<vector<int> >
#define pl pair<ll,ll>
#define pb push_back
#define PI 3.14159265
#define mod 998244353
#define pb push_back
#define mp make_pair
#define fri(s,n) for(int i=s;i<n;i++)
#define frj(s,n) for(int j=s;j<n;j++)
#define T(i) int i=1;cin>>i;while(i--)
#define vsi vector<set<int> >
#define pii pair<int,int>
#define inf 1e9
#define vpii vector<pair<int,int> >


ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b&1)
        return a*power(a,b-1);
    ll temp=power(a,b/2);
    return temp*temp;
    }
bool mycompare(ll a,ll b){
    return a>b;
    }
ll dp[3005][3005];
ll solve(vector<int> &a,int i,int j){
    if(i==j)
        return a[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=max(a[i]-solve(a,i+1,j),a[j]-solve(a,i,j-1));

    }
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast;
    int n;
    cin>>n;
    vi a(n);
    memset(dp,-1,sizeof dp);
    fri(0,n)
        cin>>a[i];
    dp[0][n-1]=solve(a,0,n-1);
    cout<<dp[0][n-1];

}
