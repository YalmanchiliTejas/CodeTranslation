#include <stdio.h>

int main(void)
{
	int i,j,k;
	int n,m;
	int temp;
	int maxtime;

	int date[20000];
	
	for(;;){
		for(i=0;i<20000;i++){
			date[i]=0;
		}
		maxtime=0;
		/////////////////////////ここから入力
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		
		for(i=0;i<m+n;i++){
			scanf("%d",&date[i]);
		}

		for (i=0;i<m+n-1;i++) {
			for (j=m+n-1;j>i;j--) {
				if (date[j-1]>date[j]) {  
					temp = date[j];        
					date[j] = date[j-1];
					date[j-1]= temp;
				}
			}	
		}
		////////////////////////////ここまでデータ整理　ここから比較
		
		maxtime = date[0];
		
		for(i=0;i<n+m-1;i++){
			if(maxtime<date[i+1]-date[i]) maxtime = date[i+1]-date[i];
		}
		
		printf("%d\n",maxtime);
		
	}
	return 0;
}