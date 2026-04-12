#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin>>N;
  int sz=1<<N;
  vector<int> dp(sz),nx(sz);
  string S;
  cin>>S>>dp;
  auto win=[&](int a,int b){if(a>b){swap(a,b);} return S[b-a-1]=='0'?a:b;};
  for(int i=N;i>0;i--){
    for(int j=0;j<sz;j+=1<<i){
      for(int k=0;k<1<<i;k+=2){
        int idx=j+k;
        nx[idx/2]=win(dp[idx],dp[idx+1]);
        nx[sz/2+idx/2]=win(dp[idx+1],dp[k+2==(1<<i)?j:idx+2]);
      }
    }
    swap(dp,nx);
  }
  for(auto &I:dp){cout<<I<<endl;}
  

  return 0;
}

