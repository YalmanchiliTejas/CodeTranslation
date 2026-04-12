#include<stdio.h>
#include<string.h>

int main(void){
	int t,s,e,n,ans,i,ex;
	char str[21];
	const char *tmp[] = {
		"North","East","South","West","Right","Left",
	};
	for(;;){
		scanf("%d",&n);
		if(n==0)break;
		ans = 0;
		t=1;
		s=2;
		e=3;
		while(n--){
			scanf("%s",str);
			for(i=0;i<6;i++){
				if(strcmp(str,tmp[i])==0)break;
			}
			switch(i){
				case 0:
					ex = t;
					t = s;
					s = 7 - ex;
					break;
				case 1:
					ex = t;
					t = 7 - e;
					e = ex;
					break;
				case 2:
					ex = t;
					t = 7 - s;
					s = ex;
					break;
				case 3:
					ex = t;
					t = e;
					e = 7 - ex;
					break;
				case 4:
					ex = e;
					e = 7 - s;
					s = ex;
					break;
				case 5:
					ex = e;
					e = s;
					s = 7 - ex;
					break;
			}
			ans += t;
			//printf("%d %d %d\n",t,s,e);
		}
		printf("%d\n",ans+1);
	}
	
	return 0;
}