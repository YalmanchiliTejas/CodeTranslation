#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
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
  ll N,Q;
  cin>>N>>Q;
  vector<int> A(N),dp(N,0);
  dp[0]=dp[1]=1;
  int idx=0;
  for(int i=0;i<N;i++){A[i]=i;}
  for(int i=0;i<Q;i++){
    ll a,b;
    cin>>a>>b;
    a--; b--;
    swap(A[a],A[b]);
    if(A[a]==0){idx=a;}
    if(A[b]==0){idx=b;}
    if(idx>0){dp[A[idx-1]]=1;}
    if(idx+1<N){dp[A[idx+1]]=1;}
  }
  ll sum=0;
  for(auto &I:dp){sum+=I;}
  cout<<sum<<endl;

  return 0;
}
