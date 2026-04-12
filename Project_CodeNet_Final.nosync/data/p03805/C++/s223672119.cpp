#include <bits/stdc++.h>
using namespace std;

int kensaku(int s,int g,vector<pair<int,int>> H){
  for(int i=0;i<H.size();i++){
    if(s==H.at(i).first&&g==H.at(i).second)
      return 1;
    if(g==H.at(i).first&&s==H.at(i).second)
      return 1;
  }
  return 0;
}

int main(){
  int N,M,a,b,ans=0,ac=0;
  cin>>N>>M;
  vector<pair<int,int>> H;
  vector<int> v(N);
  for(int i=0;i<M;i++){
    cin>>a>>b;
    H.push_back(make_pair(a,b));
  }
  for(int i=1;i<=N;i++)
    v.at(i-1)=i;

  sort(v.begin(), v.end());
  do {
    ac=0;
    // 1行で今の並び方を出力
    for (int i=0;i<N-1;i++) {
      if(kensaku(v.at(i),v.at(i+1),H)==0){
        ac=1;
        break;
      }
    }
    if(ac==0)
      ans++;
  } while (next_permutation(v.begin()+1, v.end()));

  cout <<ans<<endl;
}