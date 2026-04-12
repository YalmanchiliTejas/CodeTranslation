#include <bits/stdc++.h>
using namespace std;

int main() {
 //最初にZを引く
 //forでまわす
 //aは椅子の長さbは人の幅cは人と人の間
  
  int a,b,c;
  	cin>>a>>b>>c;
  a-=c;
  int sum=0;
  
  for(int i=0;i<100001;i++){
	a-=(b+c);
    sum+=1;
    
    if(a<(b+c)){
      cout<<sum<<endl;
      break;
    }
  }
    
}
