#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  int N;
  cin>>N;
  vector<char> cha;
  string S[N];
  for(int i=0;i<N;i++){
    cin>>S[i];
    sort(S[i].begin(),S[i].end());
  }
  sort(S,S+N);
  for(int i=0;i<S[0].size();i++){
    int cnt=0;
    for(int j=1;j<N;j++){
      for(int k=0;k<S[j].size();k++){
        if(S[j][k]==S[0][i]){
          S[j][k]='0';
          cnt++;
          break;
        }
      }
    }
    if(cnt==N-1) cha.push_back(S[0][i]);
  }
  sort(cha.begin(),cha.end());
  if(cha.size()==0){
    cout<<""<<endl;
    return 0;
  }
  for(int i=0;i<cha.size();i++) cout<<cha[i];
  cout<<endl;
}
