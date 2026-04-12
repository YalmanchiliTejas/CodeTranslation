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
  ll N;
  cin>>N;
  vector<pll> A(N);
  cin>>A;
  if(N==1){cout<<0<<endl; return 0;}
  else if(N==2){cout<<min(abs(A[0].F-A[1].F)*abs(A[0].S-A[1].S),abs(A[0].F-A[1].S)*abs(A[0].S-A[1].F))<<endl; return 0;}
  ll mx=-1,idx1=-1,mi=MOD,idx2=-1;
  for(int i=0;i<N;i++){
    auto &I=A[i];
    if(I.F>I.S){swap(I.F,I.S);}
    if(mx<I.S){mx=I.S; idx1=i;}
    if(mi>I.F){mi=I.F; idx2=i;}
  }
  ll mx2=MOD,mi2=-1;
  for(int i=0;i<N;i++){
    auto &I=A[i];
    if(i==idx1 && i==idx2){continue;}
    if(i==idx1){mi2=max(mi2,I.F);}
    else if(i==idx2){mx2=min(mx2,I.S);}
    else{mi2=max(mi2,I.F); mx2=min(mx2,I.S);}
  }
  ll ans=(mx-mx2)*(mi2-mi);
  if(idx1!=idx2){
    mx2=max(A[idx1].F,A[idx2].S);
    mi2=min(A[idx1].F,A[idx2].S);
    vector<pll> B;
    for(int i=0;i<N;i++){
      if(i!=idx1 && i!=idx2){B.push_back(A[i]);}
    }
    sort(B.begin(),B.end());
    mx2=max(mx2,B.back().F);
    ans=min(ans,(mx2-min(mi2,B[0].F))*(mx-mi));
    for(int i=0;i+3<N;i++){
      mx2=max(mx2,B[i].S);
      mi2=min(mi2,B[i].S);
      ans=min(ans,(mx2-min(mi2,B[i+1].F))*(mx-mi));
    }
    mx2=max(mx2,B.back().S);
    ans=min(ans,(mx2-min(mi2,B[0].S))*(mx-mi));
  }
  cout<<ans<<endl;
  


  return 0;
}
