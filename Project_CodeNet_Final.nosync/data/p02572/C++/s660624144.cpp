        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200002;
const int MOD =1000000007;
   int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
     signed main(){
 int n,ans1=0,ans2=0;
 cin>>n;
 int a;
 for(int i=0;i<n;i++){
     cin>>a;
     ans1=(ans1+a*a)%MOD;
     ans2=(ans2+a)%MOD;
 }
 cout<<(ans2*ans2%MOD+MOD-ans1)%MOD*modpow(2,MOD-2,MOD)%MOD<<endl;
   }
     


 


 






    





      

        
