#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
  int s1,s2;
  vector<pair<string,int>> conclusion;

  while(1){
    pair<string,int> result;
    cin>>s1>>s2;
    if(s1==0 && s2==0) break;
    result.first="A";
    result.second=s1+s2;

    cin>>s1>>s2;
    if(s1==0 && s2==0) break;
    if(s1+s2>result.second){
      result.first="B";
      result.second=s1+s2;
    }

    cin>>s1>>s2;
    if(s1==0 && s2==0) break;
    if(s1+s2>result.second){
      result.first="C";
      result.second=s1+s2;
    }

    cin>>s1>>s2;
    if(s1==0 && s2==0) break;
    if(s1+s2>result.second){
      result.first="D";
      result.second=s1+s2;
    }

    cin>>s1>>s2;
    if(s1==0 && s2==0) break;
    if(s1+s2>result.second){
      result.first="E";
      result.second=s1+s2;
    }

    conclusion.push_back(result);

  }

  for(auto i:conclusion)
    cout<<i.first<<" "<<i.second<<endl;
}