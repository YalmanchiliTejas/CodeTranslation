#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<climits>
#include<numeric>
#include<deque>
#include<queue>
#include <utility>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

typedef queue<int> IntQueue;

int N,M;
const int MAX=16;
int A[MAX][MAX];
int visited[MAX];

void solve(){
  cin>>N>>M;
  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    A[a][b]=1;
    A[b][a]=1;
  }
  vector<int> idx(N-1);
  iota(idx.begin(),idx.end(),0);
  for(int i=2;i<N+1;i++){
    idx[i-2]=i;
  }
  int pre;
  int cnt=0;
  bool flag;
  do{
    pre=1;flag=true;
    for(int i=0;i<N-1;i++){
      if (!A[pre][idx[i]]){
        flag=false;
        break;
      }
      pre=idx[i];
    }
    if (flag)cnt++;
  }while(next_permutation(idx.begin(),idx.end()));
  cout<<cnt<<endl;
  return;
}

int main(){
  solve();
  return 0;
}
