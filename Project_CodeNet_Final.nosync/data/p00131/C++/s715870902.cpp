//38
#include<iostream>
#include<algorithm>

using namespace std;

#define M ((1<<10)-1)

int main(){
  int n;
  cin>>n;
  while(n--){
    unsigned u[10]={};
    for(int y=0;y<10;y++){
      for(int x=0;x<10;x++){
	int b;
	cin>>b;
	u[y]=(u[y]<<1)+b;
      }
    }
    unsigned a[10];
    for(a[0]=0;;a[0]++){
      unsigned c[10];
      copy(u,u+10,c);
      c[0]^=a[0]^(a[0]<<1&M)^a[0]>>1;
      c[1]^=a[0];
      for(int i=1;i<9;i++){
	a[i]=c[i-1];
	c[i]^=a[i]^(a[i]<<1&M)^a[i]>>1;
	c[i+1]^=a[i];
      }
      a[9]=c[8];
      if((a[9]^(a[9]<<1&M)^a[9]>>1^c[9])==0){
	break;
      }
    }
    for(int y=0;y<10;y++){
      for(int x=9;x>=0;x--){
	cout<<!!(1<<x&a[y])<<((x==0)?'\n':' ');
      }
    }
  }
  return 0;
}