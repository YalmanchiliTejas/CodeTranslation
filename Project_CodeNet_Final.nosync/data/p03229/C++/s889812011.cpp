#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
signed main(){
  int N,ans=0;
  cin>>N;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  sort(ALL(A));
  vi B;
  if(N%2==0){
    B.push_back(A[N/2]);
    rep(i,0,N/2-1){
      B.push_back(A[i]);
      B.push_back(A[N-1-i]);
      }
    B.push_back(A[N/2-1]);
  }
  else{
    if(A[N/2]-A[N/2-1]>A[N/2+1]-A[N/2]){
      B.push_back(A[N/2+1]);
      rep(i,0,N/2-1){
         B.push_back(A[i]);
         B.push_back(A[N-1-i]);
        }
      B.push_back(A[N/2-1]);
      B.push_back(A[N/2]);
      }
    else{
      B.push_back(A[N/2]);
      rep(i,0,N/2-1){
         B.push_back(A[i]);
         B.push_back(A[N-1-i]);
        }
      B.push_back(A[N/2+1]);
      B.push_back(A[N/2-1]);
      }
    }
  vi C;
  rep(i,1,N){
    ans+=abs(B[i]-B[i-1]);
    }
  if(N%2==0){
    C.push_back(A[N/2-1]);
    rep(i,0,N/2-1){
      C.push_back(A[N-1-i]);
      C.push_back(A[i]);
      }
    C.push_back(A[N/2]);
  }
  else{
    if(A[N/2]-A[N/2-1]>A[N/2+1]-A[N/2]){
      C.push_back(A[N/2]);
      rep(i,0,N/2-1){
         C.push_back(A[N-1-i]);
         C.push_back(A[i]);
        }
      C.push_back(A[N/2-1]);
      C.push_back(A[N/2+1]);
      }
    else{
      C.push_back(A[N/2-1]);
      rep(i,0,N/2-1){
         C.push_back(A[N-1-i]);
         C.push_back(A[i]);
        }
      C.push_back(A[N/2+1]);
      C.push_back(A[N/2]);
      }
    }
  int sum=0;
  rep(i,1,N){
    sum+=abs(C[i]-C[i-1]);
    }
  ans=max(sum,ans);
  cout<<ans<<endl;
  }


