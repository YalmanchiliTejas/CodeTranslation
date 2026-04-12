#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// #define mod (int) 998244353
// #define MOD (int) 1e9+7
// // Big two primes
// #define X 1001100011100001111ll
// #define all(a) a.begin(),a.end()
// #define for0(i, n) for (int i = 0; i < n; i++)
// #define for1(i, n) for (int i = 1; i <= n; i++)
// #define loop(i,a,b) for (int i = a; i < b; i++)
// #define bloop(i,a,b) for (int i = a ; i>=b;i--)
// #define tc(t) int t; cin >> t; while (t--)
// //#define int long long
// #define ll long long
// #define pb emplace_back
// #define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define in(x) scanf("%d", &x)
// #define rr return 0
// #define prec(n) fixed<<setprecision(n)
// #define maxpq priority_queue<int>
// #define minpq priority_queue<int, vector<int>, greater<int> >
// #define inf (int)(1e18)
// #define ini(a, i) memset(a, i, sizeof(a))
// #define vi vector<int>
// #define fi first
// #define se second
// #define endl "\n"
// #define ii pair<int, int>
// #define vii vector<ii>
// #define sz(s) s.size()

ll dp[3001][3001];//dp[i][j]-value taken by first player minus value taken by the second player in range[i,j]. 

int main(){
    int n,i,l,r;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(l=n-1;l>=0;l--){
        for(r=l;r<n;r++){
            if(r==l)
                dp[l][r]=a[l];
            else{
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }    
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}