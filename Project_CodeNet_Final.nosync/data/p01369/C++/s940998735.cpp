#include<stdio.h>

int main(){
	int i,rb,lb,cnt;
	char s[64];
	while(1){
		scanf("%s",s);
		if(s[0]=='#')break;
		i=0;cnt=0;rb=1;lb=1;
		while(s[i]!='\0'){
			if((s[i]>='a'&&s[i]<='g')||(s[i]>='q'&&s[i]<='z'&&s[i]!='u'&&s[i]!='y')){
				if(!lb)cnt++;
				rb=0;lb=1;
			}else{
				if(!rb)cnt++;
				rb=1;lb=0;
			}
			i++;
		}
		printf("%d\n",cnt);
		
	}
	return 0;
}