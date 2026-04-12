#include <cstdio>

int main(void){
  int n=0;
  scanf("%d",&n);
  while(n!=0){
    int stm[100000][2]={0};
    int stp=0;
    /*int clm[100000]={0};
      int clp=0;*/
    int i=0;
    scanf("%d",&(stm[0][1]));
    stm[0][0]=1;
    int yomi=0;
    for(i=1;i<n;i++){
      scanf("%d",&yomi);
      if(yomi==stm[stp][1]){
	stm[stp][0]++;
      }
      else{
	if(i%2==0){
	  //printf("%da%d%d\n",i,stp,yomi);
	  stp++;
	  stm[stp][1]=yomi;
	  stm[stp][0]=1;
	}
	else{
	  if(stp!=0){
	    //printf("%db\n",i);
	    stp--;
	    stm[stp][0]+=stm[stp+1][0]+1;
	    stm[stp+1][0]=0;
	    stm[stp+1][1]=yomi;
	  }
	  else{
	    //printf("%dc\n",i);
	    stm[stp][0]++;
	    stm[stp][1]=yomi;
	  }
	}
      }
    }
    int ans=0;
    for(i=0;i<=stp;i++){
      if(stm[i][1]==0){
	ans+=stm[i][0];
      }
      //printf("%d%d\n",stm[i][0],stm[i][1]);
    }
    printf("%d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}



    