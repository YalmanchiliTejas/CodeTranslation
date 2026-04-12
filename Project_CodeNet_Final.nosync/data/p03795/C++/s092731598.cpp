#include <stdio.h>

using namespace std;

int main() {
  int N,X=800,Y=15,BACK,B,A,TOTAL;

scanf("%d",&N);

B=N*X;
A=N/15;
BACK=200*A;
TOTAL=B-BACK;
printf("%d\n",TOTAL);



  return 0;
}




