#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<LL> vl;
typedef vector<vector<LL>> vvl;
typedef vector<vector<vector<LL>>> vvvl;


const int inf = 1e9+7;
const LL INF = 1e18+5;
const LL mod = 1e9+7;
const int mxN = 1e5+5;
const int mxM = 1e5+5;

LL power(LL x, LL y, LL m) 
{ 
    if (y == 0) 
        return 1; 
    LL p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

LL modInverse(LL a, LL m) 
{ 
    return power(a,m-2,m);
} 

LL findProductSum(vl &A, LL n) 
{ 
    LL array_sum = 0ll; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum + A[i])%mod; 
    LL array_sum_square = (array_sum * array_sum)%mod; 
    LL individual_square_sum = 0ll; 
    for (int i = 0; i < n; i++) 
        individual_square_sum = (individual_square_sum+ (A[i]*A[i])%mod)%mod; 
    LL x = array_sum_square - individual_square_sum;
    if(x<0) x += mod;
    return x*(modInverse(2,mod))%mod;
} 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\Coding\\Programming\\input.txt", "r", stdin);
    freopen("E:\\Coding\\Programming\\output.txt", "w", stdout);
    #endif
    LL n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<findProductSum(a,n)<<endl;
}