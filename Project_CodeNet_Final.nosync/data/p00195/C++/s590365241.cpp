#include <stdio.h>
int main(){
  int  a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,a,b,c,d,e,x,y,X,Y;
  char max;

    while(1){
      scanf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2,&e1,&e2);
      
      if(a1==0||a2==0)break;
      
      a=a1+a2;
      b=b1+b2;
      c=c1+c2;
      d=d1+d2;
      e=e1+e2;

      if(a>b){
	x=a;
      }else if(a<b){
	x=b;
      }
      if(c>d){
	y=c;
      }else if(c<d){
	y=d;
      }
      if(x>y){
	X=x;
      }else if(x<y){
	X=y;
      }
      if(X>e){
	Y=X;
      }else if(X<e){
	Y=e;
      }

      if(Y==a){
	max='A';
      }else if(Y==b){
	max='B';
      }else if(Y==c){
	max='C';
      }else if(Y==d){
	max='D';
      }else if(Y==e){
	max='E';
      }
      
      printf("%c %d\n",max,Y);
    }
    return 0;
}
      