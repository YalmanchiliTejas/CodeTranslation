#include<bits/stdc++.h>
#define int long long
#define double long double
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define set set<int>
#define u_set unordered_set<int>
#define pb push_back
#define endl "\n"
#define ll long long int
#define vll vector<long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define umap unordered_map 
#define mod 1000000007
#define fori(a,n) for(int i=a;i<n;i++)
#define forj(a,n) for(int j=a;j<n;j++)
#define MAX 300303
#define V vector
using namespace std;

vvi dp(3001,vi(3001,INT_MAX));
signed main()
{
    io
    int n;
    cin >> n;
    vi a(n);
    fori(0,n) cin >> a[i];
    fori(0,n){
        dp[i][i] = a[i];
    }
    fori(0,n-1){
        dp[i][i+1] = abs(a[i] -a[i+1]);
    }
    for(int i=n-3;i>=0;--i){
        for(int j=i+2;j<n;j++){
            dp[i][j] = max(a[i]-dp[i+1][j] ,a[j]- dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;


} 