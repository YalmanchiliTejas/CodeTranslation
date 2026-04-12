//40
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  map<int,int> dat;
  vector<int> ansv;
  for(int id,ans;(cin>>id).ignore()>>ans,id|ans;){
    dat[id]=ans;
    ansv.push_back(ans);
  }
  sort(ansv.rbegin(),ansv.rend());
  ansv.erase(unique(ansv.begin(),ansv.end()),ansv.end());
  for(int n;cin>>n;){
    cout<<find(ansv.begin(),ansv.end(),dat[n])-ansv.begin()+1<<endl;
  }
  return 0;
}