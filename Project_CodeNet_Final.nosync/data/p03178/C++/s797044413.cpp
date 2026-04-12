#include<bits/stdc++.h>
using namespace std;

using Lint=long long;

template<int mod> class ModInt
{
 private:
    Lint val;
 public:
    Lint value(){ return val; }
    ModInt(Lint x=0){ val=x%mod; }
    ModInt pow(int n){
        ModInt res(1),x(val);
        while(n>0){ if(n&1) res*=x; x*=x; n>>=1; }
        return res;
    }
    ModInt inv(){ return pow(mod-2); }
    ModInt& operator+=(ModInt rhs){ val+=rhs.val; if(val>=mod) val-=mod; return *this; }
    ModInt& operator-=(ModInt rhs){ val+=mod-rhs.val; if(val>=mod) val-=mod; return *this; }
    ModInt& operator*=(ModInt rhs){ val=val*rhs.val%mod; return *this; }
    ModInt& operator/=(ModInt rhs){ *this*=rhs.inv(); return *this; }
    ModInt operator+(ModInt rhs){ return ModInt(val)+=rhs; }
    ModInt operator-(ModInt rhs){ return ModInt(val)-=rhs; }
    ModInt operator*(ModInt rhs){ return ModInt(val)*=rhs; }
    ModInt operator/(ModInt rhs){ return ModInt(val)/=rhs; }
};
using mint=ModInt<1000000007>;

mint dp[100010][2][100];

int main()
{
   string K; cin>>K;
   int D; cin>>D;
   int N=K.size();

   dp[0][0][0]=1;
   for(int i=0;i<N;i++) for(int less=0;less<2;less++) for(int j=0;j<D;j++){
      int maxD=(less? 9:K[i]-'0');
      for(int d=0;d<=maxD;d++){
         dp[i+1][less|(d<maxD)][(j+d)%D]+=dp[i][less][j];
      }
   }
   mint ans=dp[N][0][0]+dp[N][1][0]-1;
   cout<<ans.value()<<endl;
   return 0;
}
