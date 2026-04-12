#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  using pii = pair<int,int>;
  vector<pii> path(M);
  
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    path.at(i)=make_pair(a,b);
  }
  
 
  vector<int> Perm(N);
  for(int i=0;i<N;i++) Perm.at(i)=i+1;
  sort(Perm.begin(),Perm.end());
  int count = 0;
  do{
    if(Perm.at(0)!=1) break;
    
    for(int i=0;i<N-1;i++){
      bool flag = false;
      pii tmp1=make_pair(Perm.at(i),Perm.at(i+1));
      pii tmp2=make_pair(Perm.at(i+1),Perm.at(i));
      for(int j=0;j<M;j++){
        if(!flag){
          if(path.at(j)==tmp1||path.at(j)==tmp2) flag = true;
        }else{break;}
      }
      if(!flag)break;
      if(i==N-2) count++; 
    }
  }while(next_permutation(Perm.begin(),Perm.end()));
  
  cout << count << endl;
  
}