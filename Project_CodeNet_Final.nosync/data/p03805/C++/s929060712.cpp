#include <bits/stdc++.h>
using namespace std;

bool hantei(vector<int> j,vector<vector<int>> &A){
  sort(j.begin(),j.end());
  for(vector<int> &i:A)
    if(i==j)
      return true;
  return false;
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(M,vector<int>(2));
  for(vector<int> &i:A){
    int j,k;
    cin>>j>>k;
    i={j-1,k-1};
    sort(i.begin(),i.end());
  }
  vector<int> v={};
  for(int i=1;i<N;i++)
    v.push_back(i);
  int k=0;
  do{
    if(!hantei({0,v.at(0)},A))
      continue;
    bool bo=false;
    for(int i=0;i<N-2;i++)
      if(!hantei({v.at(i),v.at(i+1)},A)){
        bo=true;
        break;
      }
    if(bo)
      continue;
    k++;
  }while (next_permutation(v.begin(), v.end()));
  cout<<k<<endl;
}