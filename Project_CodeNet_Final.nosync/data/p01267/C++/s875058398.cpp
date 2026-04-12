//09
#include<iostream>

using namespace std;

int main(){
  for(int n,a,b,c,x;cin>>n>>a>>b>>c>>x,n|a|b|c|x;){
    int t=0;
    int y[10000];
    for(int i=0;i<n;i++){
      cin>>y[i];
    }
    for(int i=0;;){
      while(t<=10000&&x!=y[i]){
	x=(a*x+b)%c;
	t++;
      }
      i++;
      if(!(i<n))break;
      x=(a*x+b)%c;
      t++;
    }
    cout<<((t<=10000)?t:-1)<<endl;
  }
  return 0;
}