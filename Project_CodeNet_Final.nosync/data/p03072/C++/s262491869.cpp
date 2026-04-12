#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b,c,d,sum,ans;
  string s;
  cin>>a;
  ans=0;
  b=0;c=0;
  vector<int> vec(a);
  
  for(int i=0;i<a;i++){
  	cin>>b;
    if(c<=b){
    	ans++;
      	c=b;
    }
  }
  
 
  
  cout<<ans<<endl;
  return 0;
}