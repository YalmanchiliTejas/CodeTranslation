#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define FI first
#define SE second
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int MOD=1e9+7;
const int INF=1e9+7;
const double PI=3.141592653589793238462643383279;
//
int cnt=0;
int ans=0;
int main(){
  int N,M;
  set<int> S[8];
  cin>>N>>M;
  FOR(i,0,M){
    int A,B;
    cin>>A>>B;
    A--;
    B--;
    S[A].insert(B);
    S[B].insert(A);
  }
  VE V;
  FOR(i,1,N){
    V.PB(i);
  }
  cnt=1;
  if(S[0].find(V[0])!=S[0].end()){
    FOR(i,0,N-2){
      if(S[V[i]].find(V[i+1])!=S[V[i]].end()){
        cnt++;
      }else{
        break;
      }
    }
    if(cnt==N-1){
      ans++;
    }
  }
  while(next_permutation(V.begin(),V.end())){
    cnt=1;
    if(S[0].find(V[0])!=S[0].end()){
      FOR(i,0,N-2){
        if(S[V[i]].find(V[i+1])!=S[V[i]].end()){
          cnt++;
        }else{
          break;
        }
      }
      if(cnt==N-1){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
