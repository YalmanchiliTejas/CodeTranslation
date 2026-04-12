#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000000+7;
const long long INF=-mod;

//マクロ
//型エイリアス
using ll = long long;
using P=pair<long long,long long>;
using vl=vector<long long>;
//ショートカット
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,k,n) for(int i=k;i<n;i++) //半開区間
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
//入力
#define vin(v,N) for(long long i=0;i<N;i++) cin>>v.at(i)
#define lin(n) long long n;cin>>n
#define vlin(v,N) vector<long long>v(N);for(long long i=0;i<N;i++)cin>>v.at(i)

//関数
//最大公約数
long long gcd(long long m,long long n){
  long long a=max(m,n);
  long long b=min(m,n);
  long long r=a%b;
  while(r!=0){
    a=b; b=r; r=a%b;
  }
  return b;
}
// 最小公倍数
long long lcd(long long m,long long n){
  return m*n/gcd(m,n);
}
//xのn乗
long long power(long long x,long long N){
  long long ret=1;
  for(long long i=0;i<N;i++)   
    ret*=x;
  return ret;
}
//nCr
long long C(long long n, long long r);
//nCr (mod)
long long modC(long long n, long long r) {
    vector<long long> f(n+1),inv(n+1),invf(n+1);
    f[0]=f[1]=1;
    invf[0]=invf[1]=1;
    inv[1]=1;
    for (long long i=2;i<n+1;i++) {
        f[i]=(i*f[i-1])%mod;
        inv[i]=mod-((mod/i)*inv[mod%i])%mod;
        invf[i]=(inv[i]*invf[i-1])%mod;
    }
    long long cmb=f[n]*(invf[r]*invf[n-r]%mod)%mod;
    if (n>=r) return cmb;
    else return 0;
}
//素因数分解(mapで返す)
map<long long,long long> factor(long long p){
  ll p1=p;
  map<long long,long long>ret;
  for(long long i=2;i*i<=p1;i++){
     while(p%i==0){
      ret[i]++;
      p/=i;
    }
  }
  if(p!=1)
  ret[p]++;
  return ret;
}
//素数判定
bool is_prime(long long N){
  for(long long i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}
//最大値更新
void chmax(long long &a,long long b){
  a=max(a,b);
}
//最小値更新
void chmin(long long &a,long long b){
  a=min(a,b);
}

//メイン関数
int main(){
  //doubleの桁数
  cout<<fixed<<setprecision(10);
  
  lin(N);lin(M);
  vector<vector<bool>>graph(N,vector<bool>(N,false));
  
  rep(i,M){
    lin(a);lin(b);
    graph[a-1][b-1]=true;
    graph[b-1][a-1]=true;
  }
  
  vector<int>v(N-1);
  rep(i,N-1) v[i]=i+1;
  ll res=0;
  do{
    for(int i=0;i<N-1;i++){
      ll p,q;
      if(i==0)
        p=0;
      else
        p=v[i-1];
      q=v[i];
      
      if(!graph[p][q]){
        break;
        //cout<<p<<" "<<q<<endl;
      }
      //cout<<v[i]<<" "<<v[i+1]<<endl;
      if(i==N-2) res++;
    }
  }while(next_permutation(all(v)));
  cout<<res;
}