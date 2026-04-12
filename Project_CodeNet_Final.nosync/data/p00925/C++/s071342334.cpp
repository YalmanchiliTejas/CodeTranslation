#include "bits/stdc++.h"
using namespace std;

int main(){
  string s;
  cin>>s;
  int n;
  cin>>n;

  int pu=0;
  int ka=0;

  vector<int> x(17,-1);
  vector<int> f(17,-1);
  int b=0;
  int c=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='+'){
      pu++;
      f[c]=0;
      b++;
      c++;
    }else if(s[i]=='*'){
      ka++;
      f[c]=1;
      b++;
      c++;
    }else{
      if(x[b]==-1)x[b]=0;
      x[b]*=10;
      x[b]+=s[i]-'0';
    }
  }
  int lans=x[0];
  for(int i=1;x[i]!=-1;i++){
    if(f[i-1]==0)lans+=x[i];
    if(f[i-1]==1)lans*=x[i];
  }
  //cout<<lans<<endl;

  b=0;
  c=0;
  int tmp=1;
  vector<int> tas;
  //tmp=x[0];
  for(int i=0;x[i]!=-1;i++){
    if(f[c]==0){
      tmp*=x[i];
      tas.push_back(tmp);
      //cout<<tmp<<"aaa"<<endl;
      tmp=1;
    }else{
      tmp*=x[i];
    }
    b++;
    c++;
  }
  tas.push_back(tmp);

  int mans=0;
  for(int i=0;i<tas.size();i++){
    mans+=tas[i];
    //cout<<tas[i]<<endl;
  }

  //cout<<lans<<" "<<mans<<endl;

  if(n!=lans&&n!=mans){
    cout<<"I"<<endl;
    return 0;
  }

  if(lans==mans){
    cout<<"U"<<endl;
    return 0;
  }

  if(n==mans){
    cout<<"M"<<endl;
    return 0;
  }

  if(n==lans){
    cout<<"L"<<endl;
    return 0;
  }

  return 0;

}