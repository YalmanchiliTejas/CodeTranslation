#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define ll long long
#define rn(i,n) for(int i=1;i<=n;i++)



int main (){
  int n;
  cin>>n;
  vector<vector<int>  > a(n, vector<int>(26,0));


  string str;

  r(i,n){
    cin>>str;
    r(j,str.size()){
      a.at(i).at(str.at(j)-'a')++;

    }
  }


  string ans;
  int min;

  for(int i=0;i<26;i++){
    min=100;
    for(int j=0;j<n;j++){
      if(min>a.at(j).at(i))min=a.at(j).at(i);
    }
    for(int j=0;j<min;j++){
      ans+=(char)'a'+i;
    }
  }

  cout<<ans<<endl;



  return 0;
}
