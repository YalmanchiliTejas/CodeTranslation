#include <cstdio>
#define buf 10000
using namespace std;
int B[10];
void BubbleSort(void);

int main(void){
  int i,n,m,A[20001];
  char str[buf];

  for( ; ; ){
    for(i=0;i<5;i++){
      fgets(str,sizeof(str),stdin);
      sscanf(str,"%d %d",&n,&m);
      if(n==0 && m==0) return 0;
      B[i]=n+m; A[n+m]=i;
    }
    BubbleSort();
    printf("%c %d\n",'A'+A[B[0]],B[0]);
  }
  return 0;
}

void BubbleSort(void){
  int i,j,tmp;
  for(i=0;i<4;i++){
    for(j=4;j>i;j--){ 
      if(B[j] > B[j-1]){
        tmp = B[j-1];
        B[j-1] = B[j];
        B[j] = tmp;
      }
    }
  }
}