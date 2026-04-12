#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
int main(){
  string s;
  int i,j,k;
  vector<P> v;
  while(cin >> s,s[0]!='0'){
    for(i=0;i<s.size();i++) if(s[i]==',') s[i]=' ';
    stringstream ss(s);
    P p;
    ss >> p.second >> p.first;
    v.push_back(p);
  }
  sort(v.begin(),v.end(),greater<P>());
  int rank[105]={};
  k=1;
  rank[v[0].second]=k;
  for(i=1;i<v.size();i++){
    if(v[i-1].first!=v[i].first) k++;
    rank[v[i].second]=k;
  }
  while(cin >> k) cout << rank[k] << endl;
  return 0;
}