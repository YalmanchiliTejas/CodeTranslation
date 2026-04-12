#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=(1ull<<60);
const int MOD=1000000007;
struct Nums{
    long long n;
    vector<long long> kaijo;
    long myPow(long x, long n, long m){
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return myPow(x * x % m, n / 2, m);
        else
            return x * myPow(x, n - 1, m) % m;
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
Nums nums;
int f(int n,int x){
  if(n==0){
    return 1;
  }
  if(x==1)return 0;
  int num=nums.myPow(2,n+2,inf)-3;
  int all=0;
  all=nums.myPow(2,n,inf)-1;
  if(x==num/2+1){
    return all+1;
  }
  if(x<num/2+1){
    return f(n-1,x-1);
  }
  if(x==num){
    return 2*f(n-1,num/2)+1;
  }
  else{
    return all+1+f(n-1,x-num/2-1);
  }
}
signed main(){
  int n,x;cin>>n>>x;
  cout<<f(n,x)<<"\n";
  return 0;
}
