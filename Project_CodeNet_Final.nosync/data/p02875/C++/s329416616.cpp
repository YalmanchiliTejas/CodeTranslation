#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
long long inf=(long long)1E17;
//#define i_7 (long long)(1E9+7)
#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;

//typedef long long ll;
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}

//配列のSIZEは問題ごとに定義する必要がある。
const int SIZE=10'000'010;
long long inv[SIZE+1];//各iの逆元を格納する配列。
long long kai[SIZE+1];//i!のmodを格納する配列。
long long invkai[SIZE+1];//各i!の逆元を格納する配列。
const int MOD=i_7;
void invinit(){//上の配列を初期化する関数。
    inv[1]=1;
    for(int i=2;i<=SIZE;i++){
        inv[i] = MOD - ((MOD/i)*inv[MOD%i])%MOD;
    }
    
    kai[0]=invkai[0]=1;
    for(int i=1;i<=SIZE;i++){
        kai[i]=(kai[i-1]*i)%MOD;
        invkai[i]=(invkai[i-1]*inv[i])%MOD;
    }
}

long long comb(long long a, long long b){
    if(b<0 || a<b){
        return 0;
    }
    return mod(kai[a]*mod(invkai[b]*invkai[a-b]));
}

int main(){
  invinit();
  long long n;
  cin>>n;
  long long ans = po(3LL, n);
  for(long long k = n/2 + 1; k<=n; k++){
    long long temp = comb(n,k);
    temp *= po(2LL, n-k);
    temp = mod(temp);
    ans -= 2*temp;
    ans = mod(ans);
  }
  cout<<ans<<endl;
  return 0;
}
