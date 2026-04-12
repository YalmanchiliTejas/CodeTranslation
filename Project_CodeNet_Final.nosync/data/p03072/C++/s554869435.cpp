//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int>v(n);
  int count=1;
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=1;i<n;i++){
    bool b=true;
    for(int j=0;j<i;j++){
       
      if(v[j]>v[i])b=false;
     
    }
     if(b)count++;
  }
  cout<<count<<endl;
}
  