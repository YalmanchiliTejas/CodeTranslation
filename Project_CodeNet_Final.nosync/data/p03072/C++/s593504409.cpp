#include<cstdio>
using  namespace std;
int  main () {
  int a, arr[108], max, jum=0;
  scanf("%d", &a);
  for(int i=0; i<a; i++){
  scanf("%d", &arr[i]);
  }
  max=arr[0];
  for(int i=0; i<a; i++) {
   if (max<=arr[i]){
    max=arr[i];
    jum++;
   }
  }
  printf("%d\n", jum);
}
