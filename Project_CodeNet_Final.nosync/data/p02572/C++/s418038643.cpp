#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;
int expo(int x,int y, int MOD){
    int ans = 1;
    while(y){
        if(y&1) ans = ans * x % MOD;
        x = x*x % MOD, y >>= 1;
    }
    return ans;
}
int fun(vector<int> A, int n) 
{ 
    int fun2 = 0; 
    for (int i = 0; i < n; i++) 
        fun2 = (fun2 + A[i])%mod; 
  
    int fun2_square = (fun2 * fun2)%mod; 
  
    int fun1 = 0; 
    for (int i = 0; i < n; i++) 
        fun1 =( fun1 + (A[i]*A[i])%mod)%mod; 
  
    
    int ans = (fun2_square - fun1) % mod;
    ans = (ans + mod)%mod;
    int mul = expo(2,mod-2,mod);
    ans = (ans*mul)%mod;
    return ans;
} 
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n; cin  >> n;
        vector<int> a(n);
        FOR(i,0,n) cin >> a[i];
        cout << fun(a,n);
    }    
}
