#include <stdio.h>

int main(void) {

  int id[100],correct[100],rank[100];
  int max,count=1,flag=0;
  int query;
  int n=0,i,j,temp;

  while(1) {

    scanf("%d,%d",&id[n],&correct[n]);
    //printf("%d %d",id[n],correct[n]);
    if(id[n]==0 && correct[n]==0) break;

    n++;

  }
  //printf("%d\n",n);
  /*for(i=0;i<n;i++) {
    rank[i]=id[i];
    }*/
  //for(i=0;i<n;i++) printf("%d,%d:%d\n",id[i],correct[i],rank[i]);
  /*for(i=0;i<n-1;i++) {
    for(j=0;j<n-i-1;j++) {
      if(correct[j]<correct[j+1]) {
	temp=correct[j];
	correct[j]=correct[j+1];
	correct[j+1]=temp;
	temp=rank[j];
	rank[j]=rank[j+1];
	rank[j+1]=temp;
      }
    }
    }*/
  
  max=correct[0];
  for(i=0;i<n;i++) {
    if(max<correct[i]) max=correct[i];
  }

  for(i=max;i>=0;i--) {
    for(j=0;j<n;j++) {
      if(correct[j]==i) {
	rank[j]=count;
	flag=1;
      }
    }
    if(flag==1) {
      count++;
      flag=0;
    }
  }

  //for(i=0;i<n;i++) printf("%d,%d:%d\n",id[i],correct[i],rank[i]);
  while(scanf("%d",&query)!=EOF) {

    for(i=0;i<n;i++) {
      if(query==id[i]) printf("%d\n",rank[i]);
    }

  }

  return 0;
}

    