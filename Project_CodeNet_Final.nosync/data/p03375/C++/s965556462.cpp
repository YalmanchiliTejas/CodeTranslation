#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> bool chmin(T& a,const T& b) {
  if(a>b) {
    a=b;
    return true;
  }
  return false;
}
template<class T> bool chmax(T& a,const T& b) {
  if(a<b){
    a=b;
    return true;
  }
  return false;
}

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}
int mod;
struct Int {
  unsigned x;
  static int mpow(long long a,int k,int mod2=mod){
    long long res=1;
    while(k){
      if(k&1) res=res*a%mod2;
      a=a*a%mod2;
      k>>=1;
    }
    return res;
  }
  int inverse(Int a){
    return mpow(a.x,mod-2);
  }
  Int(): x(0) { }
  Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
  int get() const { return (int)x; }
  
  Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int &operator=(Int that) { x=that.x; return *this;}
  Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  Int &operator- () { x=mod-x; if(x==mod) x=0; return *this;}
  bool operator==(Int that){ return x==that.x; }
  bool operator!=(Int that){ return x!=that.x; }


  Int operator+(Int that) const { return Int(*this) += that; }
  Int operator-(Int that) const { return Int(*this) -= that; }
  Int operator*(Int that) const { return Int(*this) *= that; }
  Int operator/(Int that) const { return Int(*this) /= that; }

};


namespace std{
  ostream &operator <<(ostream& out,const Int& a){
    out<<a.get();
    return out;
  }
  istream &operator >>(istream& in,Int& a){
    in>>a.x;
    return in;
  }
};

//const int INF=5e8;
int n;

Int C[3005][3005];

Int dp[3005][3005];
int main(){
  cin>>n>>mod;
  REP(i,n+1){
    C[i][0]=1;
    REP(j,i) C[i][j+1]=C[i-1][j]+C[i-1][j+1];
  }

  REP(i,n+1) REP(j,i+1){
    if(i==0) dp[i][j]=1;
    else if(j>0) dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
  }

  Int res=Int::mpow(2,Int::mpow(2,n,mod-1));//tot
  //subtract NG

  for(int K=1;K<=n;++K){
    //i-ko NG
    Int tmp=C[n][K];
    tmp*=Int::mpow(2,Int::mpow(2,n-K,mod-1));
    Int tot=0;
    Int base=Int::mpow(2,n-K);
    Int pw=1;
    for(int i=1;i<=K;++i){

      Int tmp2=dp[K][i]*pw*i;
      pw*=base;
      tmp2+=dp[K][i]*pw;
      tot+=tmp2;
    }
    res-=tmp*tot*(K&1?1:-1);
  }
  cout<<res<<endl;
  return 0;
}



