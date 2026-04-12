#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nPn(vector<int>vec){
  vector<vector<int>>tmp(0);
  sort(vec.begin(),vec.end());
  do{
    tmp.push_back(vec);
  }while (next_permutation(vec.begin(),vec.end()));
  return tmp;
}

bool is_there_path(int M,vector<int>A,vector<int>B,int j1,int j2){
  bool res = false;
  for (int i=0;i<M;i++){
    if (A.at(i)-1 == j1 && B.at(i)-1 == j2){
      res = true;
    }
    if (A.at(i)-1 == j2 && B.at(i)-1 == j1){
      res = true;
    }
  }
  return res;
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int>A(M);
  vector<int>B(M);
  for (int i=0;i<M;i++){
    cin >> A.at(i) >> B.at(i);
  }
  vector<int>S(N);
  for (int i=0;i<N;i++){
    S.at(i) = i;
  }
  vector<vector<int>>R;
  R = nPn(S);
  int ans = 0;
  for (int i=0;i<R.size();i++){
    if (R.at(i).at(0)==0){
      bool res = true;
      for (int j=0;j<R.at(i).size()-1;j++){
        int j1 = R.at(i).at(j);
        int j2 = R.at(i).at(j+1);
        if (!is_there_path(M,A,B,j1,j2)){
          res = false;
        }
      }
      if (res){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
