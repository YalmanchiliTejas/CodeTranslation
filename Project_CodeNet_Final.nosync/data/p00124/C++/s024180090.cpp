#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	int i,j,temp;
	int w[200],l[200],d[200],a[200];
	int s[200];
	char team[10][21],m[21];
	scanf("%d",&n);
	while(n!=0){
		for(i=0;i<n;i++){
			s[i]=0;
			scanf("%s %d %d %d",team[i],&w[i],&l[i],&d[i]);
			s[i]=w[i]*3+l[i]*0+d[i]*1;
			a[i]=i;
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(s[i]<s[j]){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
					strcpy(m,team[i]);
					strcpy(team[i],team[j]);
					strcpy(team[j],m);
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
				else if(s[i]==s[j] && a[i]>a[j]){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
					strcpy(m,team[i]);
					strcpy(team[i],team[j]);
					strcpy(team[j],m);
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(i=0;i<n;i++){
			printf("%s,%d\n",team[i],s[i]);
		}
		scanf("%d",&n);
		if(n!=0){
			printf("\n");
		}
	}
	return 0;
}