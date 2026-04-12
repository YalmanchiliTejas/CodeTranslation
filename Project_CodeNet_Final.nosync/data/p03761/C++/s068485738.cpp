#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string>S(N);
  for(int i=0;i<N;i++)
    cin >> S.at(i);
  map<int,int>k;
  map<int,int>h;
  for(int i=0;i<28;i++)
    k[i]=1000000000;
  for(int i=0;i<N;i++){
    for(int i=0;i<28;i++)
    h[i]=0;
    for(int j=0;j<S.at(i).size();j++)
      h[S.at(i).at(j)-'a']++;
    for(int j=0;j<28;j++)
      k[j]=min(k[j],h[j]);
  }
  string ans="";
  for(int i=0;i<28;i++){
    for(int j=0;j<k[i];j++)
      ans+='a'+i;
  }
  cout << ans << endl;
  return 0;
}