#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int I=X;I<Y;I++)
#define REP(I,X,Y) for(int I=Y-1;I>=X;I--)
#define INF 1000000007
using namespace std;

int adj[10][10];

int main(){
  int N,M,ans=0,a,b;
  cin >> N >> M;
  FOR(i,0,M){
    cin >> a >> b;
    adj[a][b]=1;
    adj[b][a]=1;
  }
  vector<int> v(N);
  FOR(i,1,N+1)v[i-1] = i;
  do{
    bool flag = 1;
    FOR(i,0,N-1)if(!adj[v[i]][v[i+1]])flag = 0;
    if(flag)ans++;
  }while(next_permutation(v.begin()+1,v.end()));
  cout << ans << endl;
}
