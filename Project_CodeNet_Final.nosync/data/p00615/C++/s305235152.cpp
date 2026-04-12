#include <stdio.h>

main(){
  int n, m, tl[10001], tr[10001], i, j, k, max, data[20005] ;

  while(1){
    scanf("%d %d", &n, &m);
    if(n==0 && m==0) break;

    for(i=0;i<n;i++){
      scanf("%d", &tl[i]);
    }
    tl[i]=1000001;

    for(i=0;i<m;i++){
      scanf("%d", &tr[i]);
    }
    tr[i]=1000001;

    j=0;
    k=0;
    data[0]=0;
    for(i=1;i<m+n+1;i++){
      if(tl[j]<=tr[k]){
	data[i]=tl[j];
	j++;
      }
      else if(tl[j]>tr[k]){
	data[i]=tr[k];
	k++;
      }
    }

    max=-1;
    for(i=0;i<m+n;i++){
      //printf("%d ", data[i]);
      if(max<data[i+1]-data[i]) max=data[i+1]-data[i];
    }
    printf("%d\n", max);
    //printf("\n");
  }
  return 0;
}