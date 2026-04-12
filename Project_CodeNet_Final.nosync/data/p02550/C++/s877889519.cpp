#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const long long mod=998244353;

int main(){
  int64_t N,X,M;
  cin>>N>>X>>M;
  vector<int>id(M,-1);
  vector<int>a;
  int len=0;
  int64_t tot=0;
  while(id[X]==-1){
    a.push_back(X);
    id[X]=len;
    len++;
    tot+=X;
    X=(X*X)%M;
  }
  int c=len-id[X];
  int64_t s=0;
  for(int i=id[X];i<len;i++){s+=a[i];}
  int64_t ans=0;
  if(N<=len){
    for(int i=0;i<N;i++){
      ans+=a[i];  
    }
  }
  else{//cout<<tot<<endl;
    ans+=tot;
    N-=len;
    ans+=s*(N/c);
    N%=c;
    for(int i=0;i<N;i++){
      ans+=a[id[X]+i];
    }
  }
  cout<<ans<<endl;
  return 0;                       
}