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
int N;
int dfs(int K,bitset<8> B,vii A){
  bool flag=1;
  int R=0;
  rep(i,0,A[K].size()){
    if(!B.test(A[K][i])){
      bitset<8> C=B;
      C.set(A[K][i]);
      R+=dfs(A[K][i],C,A);
      flag=0;
    }
  }
  if(flag){
    if(B.count()==N)
      return 1;
    return 0;
  }
  return R;
}
signed main(){
  int M; cin>>N>>M;
  vii A(N);
  rep(i,0,M){
    int X,Y; cin>>X>>Y;
    A[X-1].push_back(Y-1);
    A[Y-1].push_back(X-1);
  }
  bitset<8> B;
  B.set(0);
  cout<<dfs(0,B,A)<<endl;
  }

