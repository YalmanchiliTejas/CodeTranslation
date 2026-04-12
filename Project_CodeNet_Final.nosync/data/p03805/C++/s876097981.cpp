#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<int>>&sen,int now,map<int,int>alr){
  bool ok=true;
  alr[now]=1;
  for(auto x:alr){
    if(x.second!=1)
      ok=false;
  }
  if(ok){
    return 1;
   // cout << now << "#1" << endl;
  }
  int ans=0;
  for(int i=0;i<sen.at(now).size();i++){
    if(alr[sen.at(now).at(i)]==0)
    ans += check(sen,sen.at(now).at(i),alr);
  }
  //cout << now << "#" << ans << endl;
  return ans;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>>sen(n);
  int a,b;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    sen.at(a-1).push_back(b-1);
    sen.at(b-1).push_back(a-1);
  }
  map<int,int>alr;
  for(int i=0;i<n;i++)
    alr[i]=0;
  cout << check(sen,0,alr) << endl;
  return 0;
} 