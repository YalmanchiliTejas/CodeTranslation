#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main(void)
{
	int n,m,i,cnt,sam,y;
	int t[10001];
	char s[10002][9],fb[9]="FizzBuzz",b[5]="Buzz",f[5]="Fizz";
	while(1){
		scanf("%d %d",&m,&n);
		if(m==0&&n==0) break;
		for(i=1;i<=n;i++) scanf("%s", s[i]);
		for(i=0;i<=m;i++) t[i]=i;
		cnt=0; sam=0;
		for(i=1;i<=n;i++){
			//printf("i=%d m=%d sam=%d cnt=%d\n",i,m,sam,cnt);
			char k[10]={0};
			sprintf(k,"%d",i);
			//printf("%s %s\n",s[i],k);
			if(i%3==0&&i%5==0){
				if(0!=strcmp(s[i],fb)){
					//printf("AA %d %d %s ",i,(i-sam)%m,s[i]);
					t[(i-sam)]=M;// printf("%d %d\n",i-sam,t[(i-sam)]);
					cnt++;
				}	
			}
			else if(i%5==0){
				if(0!=strcmp(s[i],b)){
					//printf("BB %d %d %s ",i,(i-sam)%m,s[i]);
					t[(i-sam)]=M;//printf("%d %d\n",i-sam,t[(i-sam)]);
					cnt++;
				}
			}
			else if(i%3==0){
				if(0!=strcmp(s[i],f)){
					//printf("CC %d %d %s ",i,(i-sam)%m,s[i]);
					t[(i-sam)]=M;//printf("%d %d\n",i-sam,t[(i-sam)]);
					cnt++;
				}
			}
			else if(0!=strcmp(s[i],k)) t[(i-sam)]=M, cnt++;
			if((i-sam)%m==0) sort(t,t+m+1),sam+=m,m-=cnt,cnt=0;
			if(m-cnt==1) break;
		}
		sort(t,t+m+1);
		m-=cnt;
		//printf("%d\n",m);
		for(i=1;i<m;i++) printf("%d ",t[i]);
		printf("%d\n",t[m]);
	}
	return 0;
}
