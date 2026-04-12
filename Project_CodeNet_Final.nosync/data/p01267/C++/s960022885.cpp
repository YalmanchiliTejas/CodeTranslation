#include<iostream>
using namespace std;

int a,b,c;
int rcount;
 
int ran(int x){
  return (a*x+b)%c;
}

int main(){
  int n,x,xf;
  int y[101];

  while(1){
    rcount=0;
    cin >> n >> a >> b >> c >> x;
    xf=x;
    if(n==0 && a==0 && b==0 && c==0 && n==0)break;
    for(int i=0;i<n;i++){
      cin >> y[i];
    }
    for(int i=0;i<n;i++){
      if(xf!=y[0]){
	while(rcount<=10001){
	    x=ran(x);
	    rcount++;
	  if(x==y[i]){
	    break;
	  }
	}
      }
      xf=-1;
    }
    if(rcount<=10000){
      cout << rcount << endl;
    }else{
      cout << -1 << endl;
    }
  }
}