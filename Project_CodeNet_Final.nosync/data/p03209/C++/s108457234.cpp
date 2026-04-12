#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <cmath>
#include <cctype>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}


ll lenb[51];
ll nump[51];

ll func(ll N,ll X){
  if(N==0){
    return (X>=1?1:0);
  }else if(X<=1+lenb[N-1]){
    return func(N-1,X-1);
  }else{
    return nump[N-1] + 1 + func(N-1,X-2-lenb[N-1]);
  }
}

int main(){
  ll N,X; cin>>N>>X;
  //長さとパティの数
  lenb[0] = 1;
  nump[0] = 1;
  for(int i=1;i<=N;++i){
    lenb[i] = lenb[i-1]*2 + 3;
    nump[i] = nump[i-1]*2 + 1;
  }
  cout << func(N,X) <<"\n";
}