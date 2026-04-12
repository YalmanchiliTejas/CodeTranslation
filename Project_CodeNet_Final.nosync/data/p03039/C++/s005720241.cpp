// #include <bits/stdc++.h>
#include<climits>
#include<cmath>
#include<cstdio>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<string>
#include<tuple>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define BEGIN ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define END return EXIT_SUCCESS
#define rep(I,N) for(auto I=0;I<(N);++I)
#define up(I,A,B) for(auto I=(A);I<=(B);++I)
#define dw(I,A,B) for(auto I=(A);I>=(B);--I)
#define all(C) (C).begin(),(C).end()
#define rall(C) (C).rbegin(),(C).rend()
#define ft first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pf push_front
#define pb push_back
#define pt pop_front
#define pk pop_back
#define lb lower_bound
#define ub upper_bound
#define rs resize
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>inline void                                      in(T &p){cin>>p;}
template<class T1,class T2>inline void                            in(T1 &p1,T2 &p2){cin>>p1>>p2;}
template<class T1,class T2,class T3>inline void                   in(T1 &p1,T2 &p2,T3 &p3){cin>>p1>>p2>>p3;}
template<class T1,class T2,class T3,class T4>inline void          in(T1 &p1,T2 &p2,T3 &p3,T4 &p4){cin>>p1>>p2>>p3>>p4;}
template<class T1,class T2,class T3,class T4,class T5>inline void in(T1 &p1,T2 &p2,T3 &p3,T4 &p4,T5 &p5){cin>>p1>>p2>>p3>>p4>>p5;}
template<class T>inline void                             out(T p){cout<<p<<endl;}
template<class T1,class T2>inline void                   out(T1 p1,T2 p2){cout<<p1<<" "<<p2<<endl;}
template<class T1,class T2,class T3>inline void          out(T1 p1,T2 p2,T3 p3){cout<<p1<<" "<<p2<<" "<<p3<<endl;}
template<class T1,class T2,class T3,class T4>inline void out(T1 p1,T2 p2,T3 p3,T4 p4){cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;}
class math{
private:
  long MOD;
public:
  math(){
    MOD=1000000007;
  }
  math(long mod){
    MOD=mod;
  }
  long mod_add(long a,long b){
    a%=MOD;
    a+=b;
    if(a>=MOD)a-=MOD;
    return a;
  }
  long mod_sub(long a,long b){
    a%=MOD;
    a-=b;
    if(a<0)a+=MOD;
    return a;
  }
  long mod_mul(long a,long b){
    a%=MOD;
    a*=b;
    if(a>=MOD)a%=MOD;
    return a;
  }
  long mod_div(long a,long b){
    a%=MOD;
    a/=b;
    return a;
  }
  long mod_pow(long a,long n){
    long r=1;
    while(n)r=r*((n%2)?a:1)%MOD,a=a*a%MOD,n>>=1;
    return r;
  }
  long nCr(long n,long r){
    if(n<0||r<0||r>n)return 0;
    long p=1,q=1;
    r=min(r,n-r);
    for(long i=1;i<=r;i++,n--)p=p*n%MOD,q=q*i%MOD;
    return p*mod_pow(q,MOD-2)%MOD;
  }
  long nHr(long n,long r){return (n==0&&r==0)?1:nCr(n+r-1,r);}
  map<long,long> prime_decomp(long n){
    map<long,long> m;
    for(long i=2;i*i<=n;i++){
      while(n%i==0){
        m[i]++;
        n/=i;
      }
    }
    if(n>1)m[n]++;
    return m;
  }
  bool is_prime(long n) {
    if(n<=1)return false;
    for(long i=2;i*i<=n;i++){
      if(n%i==0)return false;
    }
    return true;
  }
  vector<long> divisor(long n){
    vector<long>res;
    for(long i=1;i*i<=n;i++){
      if(n%i==0){
        res.push_back(i);
        if(i!=n/i)res.push_back(n/i);
      }
    }
    return res;
  }
}math;
long N,M,K,MOD=(long)1e9+7,sum;
inline void solve(void){
  in(N,M,K);
  up(d,1,M-1)sum=(sum+d*(M-d)*N*N)%MOD;
  up(d,1,N-1)sum=(sum+d*(N-d)*M*M)%MOD;
  out((math.nCr(N*M-2,K-2)*sum)%MOD);
}
int main(int argc,char**argv){
  BEGIN;
  solve();
  END;
}
