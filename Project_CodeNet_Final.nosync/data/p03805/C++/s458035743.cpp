#include <bits/stdc++.h>
using namespace std;

const int maxn=8;
bool graph[maxn][maxn];


int main(){
  int n,m;
  cin >> n >> m;
  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1]=graph[b-1][a-1]=true;
  }
  vector<int> v(n-1);
  for (int i=0;i<n-1;i++){
    v.at(i)=i+1;
  }
  bool flag=1;
  int count=0;
  do {
    flag=1;
    for (int j=0;j<n-2;j++){
      if(graph[0][v.at(0)]){
        if(graph[v.at(j)][v.at(j+1)]==0){
          flag=0;
        }
      }
      else{
        flag=0;
      }
    }
    if (flag){
        count++;
    }
  }
  while (next_permutation(v.begin(), v.end()));
  
  cout << count << endl;
  
}