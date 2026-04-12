#include<stdio.h>
#include<string.h>
char a[60];
int num[60];
int s[60];
int main(){
	int n;
	scanf("%d",&n);
	memset(s,51,sizeof(s));
	while(n--){
		scanf("%s",a);
		memset(num,0,sizeof(num));
		int t = strlen(a);
		for(int i = 0;i<t;i++){
			if(a[i]=='a')num[1]++;
			else if(a[i]=='b')num[2]++;
			else if(a[i]=='c')num[3]++;
			else if(a[i]=='d')num[4]++;
			else if(a[i]=='e')num[5]++;
			else if(a[i]=='f')num[6]++;
			else if(a[i]=='g')num[7]++;
			else if(a[i]=='h')num[8]++;
			else if(a[i]=='i')num[9]++;
			else if(a[i]=='j')num[10]++;
			else if(a[i]=='k')num[11]++;
			else if(a[i]=='l')num[12]++;
			else if(a[i]=='m')num[13]++;
			else if(a[i]=='n')num[14]++;
			else if(a[i]=='o')num[15]++;
			else if(a[i]=='p')num[16]++;
			else if(a[i]=='q')num[17]++;
			else if(a[i]=='r')num[18]++;
			else if(a[i]=='s')num[19]++;
			else if(a[i]=='t')num[20]++;
			else if(a[i]=='u')num[21]++;
			else if(a[i]=='v')num[22]++;
			else if(a[i]=='w')num[23]++;
			else if(a[i]=='x')num[24]++;
			else if(a[i]=='y')num[25]++;
			else if(a[i]=='z')num[26]++;
		}
		for(int j = 1;j<=26;++j){
				if(s[j]>num[j])s[j]=num[j];
		}
	}
	for(int j = 1;j<=26;++j){
		for(int i = 0;i<s[j];++i){
			printf("%c",j-1+'a');
		}
	}
		//printf("%d ",s[j]);

}