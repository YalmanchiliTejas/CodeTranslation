#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
#define F first
#define S second
main(){
  int n;
  string s;
  cin>>s;
  r(i,s.size()-1){
    if(s[i]=='A'&&s[i+1]=='C'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}