#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

/*
   cin.tie(0);
   ios::sync_with_stdio(false);
*/

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> D(M);
  for(int i=0;i<M;i++){
    cin>>D[i];
    D[i]--;
  }

  vector<int> darkness(N,-1);
  for(int i=0;i<M;i++){
    darkness[D[i]]=i;
  }
  
  vector<vector<int> > v(N,vector<int>(K));
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      cin>>v[i][j];
      v[i][j]--;
    }
  }

  vector<int> d(1<<M, INF);
  queue<int> que;
  que.push((1<<M)-1);
  d[(1<<M)-1]=0;
  while(que.size()){
    int now=que.front();que.pop();
    for(int k=0;k<K;k++){
      int next_mask=0;
      for(int m=0;m<M;m++){
	if(now & (1<<m)){
	  int next= v[D[m]][k];
	  if(darkness[next]<0)continue;
	  next_mask |= (1 << darkness[next]);
	  // cout<<next_mask<<endl;
	}
      }

      if(d[next_mask]>d[now]+1){
	d[next_mask]=d[now]+1;
	que.push(next_mask);
      }
      if(next_mask==0){
	cout<<d[0]<<endl;
	return 0;
      }
    }
  }
  cout<<d[0]<<endl;
  return 0;
}

