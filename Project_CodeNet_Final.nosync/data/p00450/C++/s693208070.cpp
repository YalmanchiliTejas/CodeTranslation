#include <iostream>
#include <stack>

using namespace std;

int main(){
  int n,m,p;
  while(cin>>n,n){
    stack<int> s;
    cin>>p;
    int q=1;
    for(int i=2;i<=n;++i){
      cin>>m;
      if(p==m) ++q;
      else if(p!=m&&i%2){
	s.push(q);q=1;p=m;
      }
      else{
	if(s.empty()){
	  ++q;p=m;continue;
	}
	++q;q+=s.top();s.pop();p=m;
      }
    }
    int a=0;
    if(!m){
      a+=q;s.pop();
    }
    while(!s.empty()){
      a+=s.top();s.pop();
      if(!s.empty()) s.pop();
    }
    cout<<a<<endl;
  }
  return 0;
}