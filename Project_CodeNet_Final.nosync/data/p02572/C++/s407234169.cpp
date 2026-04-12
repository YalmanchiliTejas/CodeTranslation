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
int bp(int x,int y, int MOD){
    int ans = 1;
    while(y){
        if(y&1) ans = ans * x % MOD;
        x = x*x % MOD, y >>= 1;
    }
    return ans;
}
int findProductSum(vector<int> A, int n) 
{ 
    int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum + A[i])%mod; 
  
    int array_sum_square = (array_sum * array_sum)%mod; 
  
    int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum =( individual_square_sum + (A[i]*A[i])%mod)%mod; 
  
    
    int ans = (array_sum_square - individual_square_sum) % mod;
    ans = (ans + mod)%mod;
    int mul = bp(2,mod-2,mod);
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
        cout << findProductSum(a,n);
    }    
}