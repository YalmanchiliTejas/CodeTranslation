#include<bits/stdc++.h>
#define N 500005
using namespace std;

string t, p;
int memo[N],memo2[N];
vector<int> v[300];


int main(){

  
  cin>>t>>p;

  int cnt=0;
  
  for(int i=0;i<t.size();i++){

    if(p[cnt]==t[i]){

      memo[cnt]=v[t[i]].size();

      memo2[cnt]=i;
      
      cnt++;
      
    }
    
    v[t[i]].push_back(i);
    
  }
  
  if(cnt!=p.size()){
    cout<<"no"<<endl;
    return 0;
  }

  memo2[cnt]=N;
  
  bool ans=true;
  
  for(int i=0;i<p.size();i++){
    
    if(memo[i]+1==v[p[i]].size()) continue;
    
    if(memo2[i+1]>v[p[i]][memo[i]+1]) ans=false;
    
  }

  if(ans) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  
  return 0;
}