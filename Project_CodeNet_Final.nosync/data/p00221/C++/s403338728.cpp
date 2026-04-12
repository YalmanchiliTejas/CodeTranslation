#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  string s;
  while(cin>>n>>m,n){
    vector<int>v;
    for(int i=0;i<n;i++)v.push_back(i+1);
    for(int i=1;i<=m;i++){
      cin>>s;
      if(i%3==0&&i%5==0){
        if(s!="FizzBuzz")v.erase(v.begin());
        else{
          v.push_back(v[0]);
          v.erase(v.begin());
        }
      }
      else if(i%3==0){
        if(s!="Fizz")v.erase(v.begin());
        else{
          v.push_back(v[0]);
          v.erase(v.begin());
        }
      }
      else if(i%5==0){
        if(s!="Buzz")v.erase(v.begin());
        else{
          v.push_back(v[0]);
          v.erase(v.begin());
        }
      }
      else{
        stringstream ss(s);
        int p;ss>>p;
        if(p!=i)v.erase(v.begin());
        else{
          v.push_back(v[0]);
          v.erase(v.begin());
        }
      }
      if((int)v.size()==1){
        for(;i<m;i++)cin>>s;
        break;
      }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
      if(i)cout<<' ';
      cout<<v[i];
    }
    cout<<endl;
  }
}