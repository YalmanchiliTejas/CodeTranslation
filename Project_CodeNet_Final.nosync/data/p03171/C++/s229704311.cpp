#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 
#define int long long int
#define ld long double
#define mod 1000000007 
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define forn(i,s, e) for (int i = s; i <= e; i++)
#define fornd(i,s, e) for (int i = s ; i >= e; i--)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define print(x) for(auto el: x) cout<<el<<" ";cout<<"\n"
#define PSET(x,y) fixed<<setprecision(y)<<x
#define bits(x) __builtin_popcount(x)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

 

 
template <typename T> 
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

const int N = 100005; 

void selfadd(int& a, int b){
    a = (a+b)%mod;
}

int dp[3001][3001];

void solve(){
    int n;
    cin>>n;
    int* arr = new int[n];
    int* ca = new int[n+1]();
    forn(i,0,n-1)
        cin>>arr[i];

    ca[n-1] = arr[n-1];
    fornd(i,n-2,0){
        ca[i] = arr[i]+ca[i+1];
    }

    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
    }


    for(int i=n-1;i>=0;i--){

        for(int j=i+1;j<n;j++){
            dp[i][j] = ca[i] - ca[j+1] - min(dp[i+1][j], dp[i][j-1]);
        }
    }

    cout<<(dp[0][n-1] - min(dp[1][n-1], dp[0][n-2]));



}   
 
int32_t main()
{
    fast;
    // int t;
    // cin>>t;
    // for(int y=1;y<=t;y++)
    {
        // cout<<"Case #"<<y<<": ";
        solve();
    }
    return 0;
} 