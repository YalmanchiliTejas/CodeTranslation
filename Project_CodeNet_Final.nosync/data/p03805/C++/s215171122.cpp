#include<iostream>
using namespace std;


int N,M;
int path[9][9];
int visit[9];


bool isAllVisit(){
  int flag=0;
  for(int i=1;i<=N;i++){
    flag += visit[i];
  }
  return (flag == N);
}

int searchGraph(int v){
  //while(!next.empty()){
  int result = 0;
  visit[v] = 1;
  if(isAllVisit()){
    visit[v] = 0;
    return 1;
  }
  else{
    for(int i=1; i<=N; i++){
      if(path[v][i] == 1 && visit[i]!=1){
 //       cout << "begin: " << v << " next: " << i <<endl;
        result += searchGraph(i); 
      }
    }
    visit[v] = 0;
    return result;
  }
}

int main(){
  cin >> N >> M ;
  int a,b;
  for(int i=0;i<M;i++){
    cin >> a >> b;
    path[a][b] = 1;
    path[b][a] = 1;
  }
  cout << searchGraph(1) << endl;

  return 0;
}
