#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100000000;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
  int N,M;
  cin >> N >> M;
  vector<int> nodes(N);
  vector<P> branches(M);
  rep(i,N){
    nodes[i] = i;
  }
  rep(i,M){
    int x,y;
    cin >> x >> y;
    x--;y--;
    branches[i].first=x;
    branches[i].second=y;
  }
  int paths=0;    
  do{
    if(nodes[0]!=0)break;
    /*rep(i,N){
        cout << nodes[i] << " ";
    }*/
    int road=0;
    rep(i,N-1){
      rep(j,M){
        int a=nodes[i];
        int b=nodes[i+1];
        if(a>b){
          swap(a,b);
        }
        if(a==branches[j].first && b==branches[j].second){
          road++;
        }
      }
    }
    if(road==N-1){
      paths++;
      /*rep(i,N){
        cout << nodes[i] << " ";
      }*/
      //cout << endl;
    }
  }while(next_permutation(nodes.begin(),nodes.end()));
  cout << paths << endl;

  return 0;
}