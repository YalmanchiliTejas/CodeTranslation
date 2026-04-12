#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define MAX 1000000

int main(){
  int n;
  cin>>n;
  vector<string> S(n);
  vector<int> count(26,100);
  for(int i=0;i<n;i++){
    cin>>S.at(i);
  }

  for(int i=0;i<n;i++){
    vector<int> num(26,0);
    for(int j=0;j<S.at(i).size();j++){
      num.at(S.at(i).at(j)-'a')++;
    }
    for(int j=0;j<26;j++){
      count.at(j)=min(count.at(j),num.at(j));
    }
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<count.at(i);j++){
      cout<<(char)(i+'a');
    }
  }
  cout<<endl;
}
