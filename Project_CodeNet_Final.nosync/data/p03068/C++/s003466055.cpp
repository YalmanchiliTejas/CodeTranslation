#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  string n;
  cin>>a>>n>>b;
  
  for(int i=0;i<a;i++){
    if(n.at(i)!=n.at(b-1)){
      n.at(i)='*';
    }
  }
  
  cout<<n<<endl;
}