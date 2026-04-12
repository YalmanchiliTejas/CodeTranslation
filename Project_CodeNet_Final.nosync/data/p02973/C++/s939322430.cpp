#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p;
  int a;
  cin>>a;
  p.insert(p.begin(),a);
  for(int i=1;i<N;i++){
    int a;
    cin>>a;
    if(p.at(0)>=a){
      p.insert(p.begin(),a);
    }
    else if(p.at(p.size()-1)<a){
      p.at(p.size()-1)=a;
    }
    else{
      int b=lower_bound(p.begin(),p.end(),a)-p.begin();
      p.at(b-1)=a;
    }
  }
  cout<<p.size()<<endl;
    
}