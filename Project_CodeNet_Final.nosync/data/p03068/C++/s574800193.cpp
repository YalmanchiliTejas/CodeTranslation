#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int N;
  cin>>N;

  string S;
  cin>>S;

  int K;
  cin>>K;

  for(int i=0;i<S.size();i++){
    if(S.at(i)!=S.at(K-1)) S.at(i)='*';
  }
  cout<<S<<endl;

}
