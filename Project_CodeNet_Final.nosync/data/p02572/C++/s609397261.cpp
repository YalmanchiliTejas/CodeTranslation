    
#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ALL(a)              a.begin(), a.end()
#define ALLN(a, n)          (a, a+n)
#define MAX                 10000007
#define MIN                 -10000007

const int mod=1e9+7;
ll d,x,y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
              
int main()
{
  ios::sync_with_stdio(0);
    cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    #endif
      
    int t;
    t=1;
     //  cin>>t;
    while(t--){
            ll n,sum=0;
            cin>>n;
            ll a[n];
            REP(i,0,n-1) {cin>>a[i];sum+=(a[i]%mod);}
            ll sq=((sum%mod)*(sum%mod))%mod;
            ll indi=0;
            REP(i,0,n-1){
              indi+=((a[i]%mod)*(a[i]%mod))%mod;
            }  
            indi%=mod;
            ll k=((sq%mod)-(indi%mod)+mod)%mod;
            ll q=modInverse(2,mod);
            cout<<(k%mod*q%mod)%mod;
       


             }
             cerr<<"Time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}
