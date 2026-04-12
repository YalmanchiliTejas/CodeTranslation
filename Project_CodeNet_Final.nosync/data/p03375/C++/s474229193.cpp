#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
using lint=long long;
const int inf=1000000007;
int MOD;
long long modpow(lint x,lint n,lint rest){
    lint res=1;lint cur=x;
    while(n>0){
        if(n&1){
            res*=cur;res%=rest;
        }
        cur*=cur;cur%=rest;n/=2;
    }
    return res;
}
struct Nums{
    long long n;
    vector<long long> kaijo;
    Nums(int N){
        n=N;
        kaijo.push_back(1);
        for(long long i=1;i<=n;i++){
            kaijo.push_back((kaijo[i-1]*i)%MOD);
        }
    }
    long long modinv(long long a, long long m) {
        long long b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }
    long long comb(long long N,long long K,long long rest){
        long long res=kaijo[N]*modinv(kaijo[K],rest)%rest;
        res*=modinv(kaijo[N-K],rest);
        res%=rest;
        return res;
    }
};

signed main(){
  int n,m;cin>>n>>m;MOD=m;
  Nums lib(n+5);
  vector<vector<lint>> S(n+5,vector<lint>(n+5,0));
  rep1(i,n+4){
      S[i][i]=1;
      S[i][1]=1;
  }
  for(int i=3;i<n+5;++i){
      rep1(j,n+4){
          if(j>i)break;
          S[i][j]=S[i-1][j]*j+S[i-1][j-1];
          S[i][j]%=m;
      }
  }
  lint res=modpow(2,modpow(2,n,m-1),m);
  lint sub=0;
  rep1(i,n){
      lint sm=0;
      lint last=-1;
      rep1(j,n){
          if(j>i)break;
          //case of 1
          lint case1=S[i][j];
          lint hoge=modpow(2,n-i,m-1);
          lint hogehoge=modpow(2,hoge,m);
          lint hogehogehoge=modpow(2,j*(n-i),m);
          case1*=hogehoge;case1%=m;
          case1*=hogehogehoge;case1%=m;
          //case of 0
          lint case2=S[i][j]*j%m;
          case2*=hogehoge;case2%=m;
          if(last==-1)case2*=modpow(2,(j-1)*(n-i),m);
          else case2*=last;case2%=m;
          last=hogehogehoge;
          //printf("case1=%lld, case2=%lld\n",case1,case2);
          sm+=case1+case2;
      }
      sm%=m;
      //printf("sm=%lld\n",sm);
      sm*=lib.comb(n,i,m);sm%=m;
      //cout<<sm<<"\n";
      if(i&1)sub+=sm;
      else{
          sub+=m-sm;
      }
      sub%=m;
  }
  res+=m-sub;res%=m;
  cout<<res<<"\n";
  return 0;
}